#ifndef SISTEMA_STELLARE_H
#define SISTEMA_STELLARE_H
#include <cassert>
#include <QString>

template <class T>
/*!
 * \brief La classe Sistema_stellare gestice un lista di Corpi_celesti
 */
class Sistema_stellare{
    typedef int size_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    /*!
     * \brief La classe Nodo immagazzina un elemento del Sistema_stellare
     */
    class Nodo{
        friend class Sistema_stellare<T>;
        value_type info; //!<info Contiene un oggetto di tipo T
        Nodo* next; //!<next Puntatore al prossimo nodo della lista

        /*!
         * \brief Costruttore di Nodo
         */
        Nodo(const value_type&, Nodo* = nullptr);

        /*!
         * \brief Costruttore di copia di Nodo
         */
        Nodo(const Nodo&);

        /*!
         * \brief Distrugge ricorsivamente la lista
         */
        void del();
    };

    QString nome;//!<nome Nome del Sistema_stellare, ovvero nome della stella
    Nodo* first, //!<first Primo Nodo della lista
    * last; //!<last Ultimo Nodo della Lista
    int nCorpi; //!<nCorpi Numero di Corpi_celesti nel Sistema_solare (usato come se fosse l'indice di posizione di un array: 0 = un Nodo)

    /*!
     * \brief Ritorna ricorsivamente una nuova copia del Nodo oggetto di invocazione, costruendo una nuova lista
     * \return puntatore al primo Nodo di una nuova lista
     */
    static Nodo* clone(Nodo*, Nodo*);

public:

    /*!
     * \brief Costruttore di default
     */
    Sistema_stellare();

    /*!
     * \brief Costruttore di Sistema_solare
     */
    Sistema_stellare(const value_type&);

    /*!
     * \brief Costruttore di copia profonda
     */
    Sistema_stellare(const Sistema_stellare&);

    /*!
     * \brief Distruttore profondo
     */
    ~Sistema_stellare();

    /*!
     * \brief Operatore di assegnazione di copia profonda
     * \return
     */
    Sistema_stellare& operator=(const Sistema_stellare&);

    /*!
     * \brief La classe Iterator crea un forward iterator sul Sistema_stellare
     */
    class Iterator{
        friend Sistema_stellare<T>;
        Nodo* ptr;
        Iterator(Nodo*);

    public:
        Iterator();
        Iterator& operator=(const Iterator&);
        Iterator &operator++();
        Iterator &operator++(int);
        reference operator*() const;
        pointer operator->() const;
        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);
        bool operator<(const Iterator&);
        bool operator<=(const Iterator&);
        bool operator>(const Iterator&);
        bool operator>=(const Iterator&);
    };

    /*!
     * \brief La classe Const_iterator crea un forward const iterator sul Sistema_stellare
     */
    class Const_iterator{
        friend class Sistema_stellare<T>;
        const Nodo* ptr;
        Const_iterator(Nodo*);

    public:
        Const_iterator();
        Const_iterator& operator=(const Const_iterator&);
        Const_iterator &operator++();
        Const_iterator &operator++(int);
        const value_type& operator*() const;
        const pointer operator->() const;
        bool operator==(const Const_iterator&);
        bool operator!=(const Const_iterator&);
        bool operator<(const Const_iterator&);
        bool operator<=(const Const_iterator&);
        bool operator>(const Const_iterator&);
        bool operator>=(const Const_iterator&);
    };

    /*!
     * \brief Ritorna nome del Sistema_stellare
     * \return nome
     */
    QString get_nome()const;

    /*!
     * \brief Aggiunge un Corpo_celeste in coda al Sistema_stellare
     */
    void add(const value_type&);

    /*!
     * \brief Rimuove un Corpo_celeste dal Sistema_stellare, ma con i=0 elimino la stella, di consegueza elimino tutto il sistema
     */
    void remove(const size_type);

    /*!
     * \brief Ritorna un Corpo_celeste per referenza facente parte del Sistema_stellare
     * \return Nodo->info
     */
    reference get(size_type)const;

    /*!
     * \brief Ritorna l'indice di posizione del Corpo_celeste ricercato oppure -1
     * \return posizione nella lista
     */
    size_type search(const value_type&)const;

    /*!
     * \brief Ritorna l'indice di posizione del Corpo_celeste ricercato tramite nome oppure -1
     * \return posizione nella lista
     */
    size_type search(const QString&)const;

    /*!
     * \brief Svuota la lista impostando il primo elemento a nullptr
     */
    void clear();

    /*!
     * \brief Verifica che il Sistema_stellare sia vuoto
     * \return true se vuoto, false altrimenti
     */
    bool empty()const;

    /*!
     * \brief Ritorna un iteratore al primo elemento del Sistema_stellare
     * \return iteratore a first
     */
    Iterator begin();

    /*!
     * \brief Ritorna un iteratore alla cella di memoria dopo l'ultimo elemento del Sistema_stellare
     * \return iteratore a last+1
     */
    Iterator end();

    /*!
     * \brief Ritorna un iteratore costante al primo elemento del Sistema_stellare
     * \return iteratore a first
     */
    Const_iterator cbegin()const;

    /*!
     * \brief Ritorna un iteratore costante alla cella di memoria dopo l'ultimo elemento del Sistema_stellare
     * \return iteratore a last+1
     */
    Const_iterator cend()const;
};

template <class T>
Sistema_stellare<T>::Nodo::Nodo(const value_type& t, Nodo* n) : info(t), next(n){}

template <class T>
Sistema_stellare<T>::Nodo::Nodo(const Nodo& n) : info(n.info), next(n.next){}

template <class T>
void Sistema_stellare<T>::Nodo::del(){
    if(next) next->del();
    delete this;
}

template <class T>
typename Sistema_stellare<T>::Nodo* Sistema_stellare<T>::clone(Nodo* first, Nodo* last){
    if(!first){
        last= nullptr;
        return nullptr;
    }
    Nodo* n= new Nodo(first->info, clone(first->next, last));
    if(!first->next) last= n;
    return n;
}

template <class T>
Sistema_stellare<T>::Sistema_stellare() : nome(""), first(nullptr), last(nullptr), nCorpi(-1){}

template <class T>
Sistema_stellare<T>::Sistema_stellare(const value_type& t) :nome(t->get_nome()), first(new Nodo(t)), last(first), nCorpi(0){

}

template <class T>
Sistema_stellare<T>::Sistema_stellare(const Sistema_stellare& s) : nome(s.nome), first(clone(s.first, last)), nCorpi(s.nCorpi){}

template <class T>
Sistema_stellare<T>::~Sistema_stellare(){
    if(first){
        nCorpi=-1;
        first->del();
    }
}

template <class T>
Sistema_stellare<T>& Sistema_stellare<T>::operator=(const Sistema_stellare& s){
    if(this != &s){
        if(first) delete first;
        first= clone(s.first, last);
        nCorpi= s.nCorpi;
        nome=s.nome;
    }
    return *this;
}

template<class T>
Sistema_stellare<T>::Iterator::Iterator(Nodo* p) : ptr(p) {}

template<class T>
Sistema_stellare<T>::Iterator::Iterator() : ptr(nullptr) {}

template<class T>
typename Sistema_stellare<T>::Iterator & Sistema_stellare<T>::Iterator::operator=(const Iterator& it){
    ptr=it.ptr;
    return *this;
}

template<class T>
typename Sistema_stellare<T>::Iterator& Sistema_stellare<T>::Iterator::operator++(){
    if(ptr) ptr=ptr->next;
    return *this;

}
template<class T>
typename Sistema_stellare<T>::Iterator& Sistema_stellare<T>::Iterator::operator++(int){
    Iterator aux=*this;
    if(ptr) ptr=ptr->next;
    return aux;

}

template<class T>
typename Sistema_stellare<T>::value_type& Sistema_stellare<T>::Iterator::operator*() const{
    return ptr->info;
}

template<class T>
typename Sistema_stellare<T>::pointer Sistema_stellare<T>::Iterator::operator->() const
{
    return &(ptr->info);
}

template<class T>
bool Sistema_stellare<T>::Iterator::operator==(const Iterator& it)
{
    return ptr == it.ptr;
}

template<class T>
bool Sistema_stellare<T>::Iterator::operator!=(const Iterator& it)
{
    return ptr != it.ptr;
}

template<class T>
bool Sistema_stellare<T>::Iterator::operator<(const Iterator& it){
        return ptr < it.ptr;
}

template<class T>
bool Sistema_stellare<T>::Iterator::operator<=(const Iterator& it){
        return ptr <= it.ptr;
}

template<class T>
bool Sistema_stellare<T>::Iterator::operator>(const Iterator& it){
        return ptr > it.ptr;
}

template<class T>
bool Sistema_stellare<T>::Iterator::operator>=(const Iterator& it){
        return ptr >= it.ptr;
}

template<class T>
Sistema_stellare<T>::Const_iterator::Const_iterator(Nodo * p) : ptr(p) {}

template<class T>
Sistema_stellare<T>::Const_iterator::Const_iterator() : ptr(nullptr) {}

template<class T>
typename Sistema_stellare<T>::Const_iterator & Sistema_stellare<T>::Const_iterator::operator=(const Const_iterator & cit){
    ptr=cit.ptr;
    return *this;
}

template<class T>
typename Sistema_stellare<T>::Const_iterator& Sistema_stellare<T>::Const_iterator::operator++(){
    if(ptr) ptr=ptr->next;
    return *this;

}
template<class T>
typename Sistema_stellare<T>::Const_iterator& Sistema_stellare<T>::Const_iterator::operator++(int){
    Iterator aux=*this;
    if(ptr) ptr=ptr->next;
    return aux;

}

template<class T>
const typename Sistema_stellare<T>::value_type& Sistema_stellare<T>::Const_iterator::operator*() const{
    return ptr->info;
}

template<class T>
const typename Sistema_stellare<T>::pointer Sistema_stellare<T>::Const_iterator::operator->() const
{
    return &(ptr->info);
}

template<class T>
bool Sistema_stellare<T>::Const_iterator::operator==(const Const_iterator& cit){
    return ptr == cit.ptr;
}

template<class T>
bool Sistema_stellare<T>::Const_iterator::operator!=(const Const_iterator& cit){
    return ptr != cit.ptr;
}

template<class T>
bool Sistema_stellare<T>::Const_iterator::operator<(const Const_iterator& cit){
        return ptr < cit.ptr;
}

template<class T>
bool Sistema_stellare<T>::Const_iterator::operator<=(const Const_iterator& cit){
        return ptr <= cit.ptr;
}

template<class T>
bool Sistema_stellare<T>::Const_iterator::operator>(const Const_iterator& cit){
        return ptr > cit.ptr;
}

template<class T>
bool Sistema_stellare<T>::Const_iterator::operator>=(const Const_iterator& cit){
        return ptr >= cit.ptr;
}

template<class T>
QString Sistema_stellare<T>::get_nome()const{
    return nome;
}

template<class T>
void Sistema_stellare<T>::add(const value_type& t){
    Nodo* corpo= new Nodo(t);
    if(!first){
        first= last= corpo;
        nome= t->get_nome();
    }else{
        Nodo* temp= first;
        while(temp->next) temp= temp->next;
        corpo->next= temp->next;
        temp->next= corpo;
        if(!corpo->next) last= corpo;
    }
    ++nCorpi;
}

template<class T>
void Sistema_stellare<T>::remove(const size_type i){
    assert(i<=nCorpi);
    if(empty()) return;
    if(!first->next){
        if(i==0){
            delete first;
            first= nullptr;
            --nCorpi;
            return;
        }
    }else{
        Nodo* prec= first;
        Nodo* corr= first->next;
        if(i==0){
            clear();
            return;
        }
        for(auto x=1; corr->next && x<i; ++x){
            prec= prec->next;
            corr=corr->next;
        }
        if(corr){
            prec->next= corr->next;
            corr->next= nullptr;
            delete corr;
            --nCorpi;
            return;
        }
    }
}

template<class T>
typename Sistema_stellare<T>::reference Sistema_stellare<T>::get(size_type i) const{
    assert(i<=nCorpi);
    assert(first);
    if(i==0) return first->info;
    if(first->next){
        Nodo* corr= first->next;
        for(auto x=1; corr->next && x<i; ++x) corr= corr->next;
        if(corr) return corr->info;
    }
}

template<class T>
typename  Sistema_stellare<T>::size_type Sistema_stellare<T>::search(const value_type& n) const{
    auto i=0;
    Nodo* corr= first;
    bool found= false;
    while(!found && corr){
        if(corr->info->isEqual(*n)) found= true;
        else{
            corr= corr->next;
            ++i;
        }
    }
    return found? i : -1;
}

template<class T>
typename Sistema_stellare<T>::size_type Sistema_stellare<T>::search(const QString& s) const{
    auto i=0;
    Nodo* corr= first;
    bool found= false;
    while(!found && corr){
        if(corr->info->get_nome()==s) found= true;
        else{
            corr= corr->next;
            ++i;
        }
    }
    return found? i : -1;
}

template<class T>
void Sistema_stellare<T>::clear(){
    if(first){
        first->del();
        first= nullptr;
    }
}

template<class T>
bool Sistema_stellare<T>::empty() const{
    return !first;
}

template<class T>
typename Sistema_stellare<T>::Iterator Sistema_stellare<T>::begin(){
    return Iterator(first);
}

template<class T>
typename Sistema_stellare<T>::Iterator Sistema_stellare<T>::end(){
    return Iterator(nullptr);
}

template<class T>
typename Sistema_stellare<T>::Const_iterator Sistema_stellare<T>::cbegin()const{
    return Const_iterator(first);
}

template<class T>
typename Sistema_stellare<T>::Const_iterator Sistema_stellare<T>::cend()const{
    return Const_iterator(nullptr);
}

#endif // SISTEMA_STELLARE_H
