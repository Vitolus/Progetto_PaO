#ifndef SISTEMA_STELLARE_H
#define SISTEMA_STELLARE_H
#include <cassert>

template <class T>
class Sistema_stellare{
    typedef std::size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::ptrdiff_t difference_type;

    class Nodo{
        friend class Sistema_stellare<T>;
        value_type info;
        Nodo* next;
        Nodo(const value_type&, Nodo* = nullptr);
        Nodo(const Nodo&);
        void del();
    };

    Nodo* first, * last;
    static Nodo* clone(Nodo*, Nodo*);

public:
    Sistema_stellare();
    Sistema_stellare(const value_type&);
    Sistema_stellare(const Sistema_stellare&);
    ~Sistema_stellare();
    Sistema_stellare& operator=(const Sistema_stellare&);

    class Iterator{
        friend Sistema_stellare<T>;
        Nodo* ptr;
        Iterator(Nodo*);

    public:
        Iterator();
        Iterator& operator=(const Iterator&);
        Iterator &operator++();
        Iterator &operator++(int);
        Iterator &operator--();
        Iterator &operator--(int);
        reference operator*() const;
        pointer operator->() const;
        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);
        bool operator<(const Iterator&);
        bool operator<=(const Iterator&);
        bool operator>(const Iterator&);
        bool operator>=(const Iterator&);
    };

    class Const_iterator{
        friend class Sistema_stellare<T>;
        const Nodo* ptr;
        Const_iterator(Nodo*);

    public:
        Const_iterator();
        Const_iterator& operator=(const Const_iterator&);
        Const_iterator &operator++();
        Const_iterator &operator++(int);
        Const_iterator &operator--();
        Const_iterator &operator--(int);
        const value_type& operator*() const;
        const pointer operator->() const;
        bool operator==(const Const_iterator&);
        bool operator!=(const Const_iterator&);
        bool operator<(const Const_iterator&);
        bool operator<=(const Const_iterator&);
        bool operator>(const Const_iterator&);
        bool operator>=(const Const_iterator&);
    };

    void add(const value_type&);
    void replace_last(size_type, const value_type&);
    void remove(const size_type);
    value_type get(size_type)const;
    size_type search(const value_type&)const;
    void clear();
    bool empty() const;
    Iterator begin();
    Iterator end();
    Const_iterator cbegin()const;
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
Sistema_stellare<T>::Sistema_stellare() : first(nullptr), last(nullptr){}

template <class T>
Sistema_stellare<T>::Sistema_stellare(const value_type& t) : first(new Nodo(t)), last(first){}

template <class T>
Sistema_stellare<T>::Sistema_stellare(const Sistema_stellare& s) : first(clone(s.first, last)){}

template <class T>
Sistema_stellare<T>::~Sistema_stellare(){
    if(first) first->del();
}

template <class T>
Sistema_stellare<T>& Sistema_stellare<T>::operator=(const Sistema_stellare& s){
    if(this != &s){
        if(first) delete first;
        first= clone(s.first, last);
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
void Sistema_stellare<T>::add(const value_type& t){
    Nodo* corpo= new Nodo(t);
    if(!first) first= last= corpo;
    else if(first->info > corpo->info){
        corpo->next= first;
        first= corpo;
    }else{
        Nodo* temp= first;
        while(temp->next && temp->next->info < corpo->info) temp= temp->next;
        corpo->next= temp->next;
        temp->next= corpo;
        if(!corpo->next) last= corpo;
    }
}

template<class T>
void Sistema_stellare<T>::replace_last(size_type i, const value_type& corpo){
    remove(i);
    add(corpo);
}

template<class T>
void Sistema_stellare<T>::remove(const size_type i){
    if(empty()) return;
    if(!first->next){
        if(i==0){
            delete first;
            first= nullptr;
            return;
        }
    }else{
        Nodo* prec= first;
        Nodo* corr= first->next;
        if(i==0){
            first= first->next;
            prec->next= nullptr;
            delete prec;
            return;
        }
        for(size_type x=1; corr->next && x<i; ++x){
            prec= prec->next;
            corr=corr->next;
        }
        if(corr){
            prec->next= corr->next;
            corr->next= nullptr;
            delete corr;
            return;
        }
    }
    return;
}

template<class T>
typename Sistema_stellare<T>::value_type Sistema_stellare<T>::get(size_type i) const{
    if(!first->next){
        if(i==0) return first->info;
    }else{
        Nodo* corr= first->next;
        if(i==0) return first->info;
        for(size_type x=1; corr->next && x<i; ++x) corr= corr->next;
        if(corr) return corr->info;
    }
    value_type temp;
    return temp;
}

template<class T>
typename  Sistema_stellare<T>::size_type Sistema_stellare<T>::search(const value_type& n) const{
    size_type i=0;
    Nodo* corr= first;
    bool found= false;
    while(!found && corr->next){
        if(corr->info == n) found= true;
        else{
            corr= corr->next;
            ++i;
        }
    }
    return i;
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
