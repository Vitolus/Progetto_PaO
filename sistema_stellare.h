#ifndef SISTEMA_STELLARE_H
#define SISTEMA_STELLARE_H
#include <cassert>
#include <QIterator>

template <class T>
class Sistema_stellare{
    typedef std::size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::ptrdiff_t difference_type;

    size_type length;
    size_type dim;
    pointer ele;
public:

    class Iterator{
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;

        T* ptr;
    public:
        Iterator(pointer p) : ptr(p){}

        reference operator*() const{
            return *ptr;
        }

        pointer operator->(){
            return ptr;
        }

        Iterator &operator++(){
            ptr++;
            return *this;
        }

        Iterator operator++(int){
            Iterator temp= *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& it){
            return ptr == it.ptr;
        }

        bool operator!=(const Iterator& it){
            return ptr != it.ptr;
        }
    };

    class Const_iterator{
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;

        T* ptr;
    public:
        Const_iterator(pointer p) : ptr(p){}

        const value_type& operator*() const{
            return *ptr;
        }

        const value_type* operator->(){
            return ptr;
        }

        Iterator &operator++(){
            ptr++;
            return *this;
        }

        Iterator operator++(int){
            Iterator temp= *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& it){
            return ptr == it.ptr_;
        }

        bool operator!=(const Iterator& it){
            return ptr != it.ptr_;
        }
    };


    Sistema_stellare() : length(), ele(nullptr){}

    /**
     * @brief costruisce Sistema_stellare vuoto con lunghezza l
     * @param l lunghezza
     */
    explicit Sistema_stellare(size_type l) : length(l){
        assert(length>=0);
        if(l>0) ele= new T[length];
        dim= 0;
    }

    /**
     * @brief copy constructor
     * @param s Sistema_stellare da copiare
     */
    Sistema_stellare(const Sistema_stellare &s){
        length= s.length;
        dim= length;
        ele= new T[length];
        for(auto i= 0; i<length; i++) ele[i]= s.ele[i];
    }

    /**
     * @brief move constructor
     * @param s Sistema_stellare da rimpiazzare
     *//*
    Sistema_stellare(Sistema_stellare &&s){
        length= s.length;
        dim= length;
        ele= s.ele;
        s.ele= nullptr;
        s.length= 0;
        s.dim= 0;
    }*/

    ~Sistema_stellare(){
        if(ele) delete [] ele;
    }

    /**
     * @brief copy assignment operator
     * @param s Sistema_solare da assegnare
     * @return nuovo Sistema_solare (*this)
     */
    Sistema_stellare &operator=(const Sistema_stellare &s){
        erase();
        length= s.length;
        dim= length;
        ele= new T[length];
        for(auto i= 0; i<length; i++) ele[i]= s.ele[i];
    }

    /**
     * @brief move assignment operator
     * @param s Sistema_solare da assegnare
     * @return nuovo Sistema_solare (*this)
     *//*
    Sistema_stellare &operator=(Sistema_stellare &&s){
        erase();
        length= s.length;
        dim= length;
        ele= s.ele;
        s.ele= nullptr;
        s.length= 0;
        s.dim= 0;
    }*/

    /**
     * @brief accede all'oggetto specificato con controllo limiti
     * @param i posizione dell'elemento
     * @return referenza elemento richiesto
     */
    reference at(size_type i){
        assert(i>=0 && i < dim);
        return ele[i];
    }

    reference operator[](value_type i){
        assert(i>=0 && i < dim);
        return ele[i];
    }

    /**
     * @brief accede al primo elemento
     * @return referenza primo elemento
     */
    reference front(){
        return ele[0];
    }

    /**
     * @brief accede all'ultimo elemento
     * @return referenza ultimo elemento
     */
    reference back(){
        return ele[dim-1];
    }

    /**
     * @brief accesso diretto all'array sottostante
     * @return puntatore primo elemento
     */
    pointer data() noexcept{
        return ele;
    }

    /**
     * @brief accesso diretto all'array sottostante costantemente
     * @return puntatore al primo elemento
     */
    const pointer data() const noexcept{
        return ele;
    }

    /**
      * @brief ritorna un iteratore all'inizio dell'array
      * @return iteratore al primo elemento
      */
    Iterator begin() noexcept{
        return Iterator(&ele);
    }

    /**
      * @brief ritorna un iteratore alla fine dell'array
      * @return iteratore all'elemento successivo all'ultimo
      */
    Iterator end() noexcept{
        return Iterator(&ele[dim]);
    }

    /**
      * @brief controlla se Sistema_stellare vuoto
      * @return vero se vuoto, falso altrimenti
      */
    bool empty() const noexcept{
        return dim==0;
    }

    /**
      * @brief ritorna dimensione occupata
      * @return dim
      */
    size_type size() const noexcept {
        return dim;
    }

    /**
      * @brief ritorna dimensione massima
      * @return length
      */
    size_type capacity() const noexcept{
        return length;
    }

    /**
      * @brief cancella gli elementi del Sistema_stellare lasciando invariata la dimensione massima
      */
    void clear() noexcept{
        delete [] ele;
        ele= new T[length];
        dim= 0;
    }

    /**
     * @brief elimina elemento in posizione pos
     * @param indice di posizione
     */
    Iterator erase(Iterator pos){
        assert(pos>=ele && pos < ele[dim]);
        Iterator temp= pos+1;
        delete pos;
        dim= dim-1;
        return temp;
    }

    /**
     * @brief aggiunge in coda elemento v
     * @param elemento da aggiungere
     */
    void push_back(const value_type& v){
        if(dim==length) reserve(2*length+1);
        ele[dim++]= v;
    }

    /**
     * @brief elimina ultimo elemento di Sistema_solare
     */
    void pop_back(){
        delete ele[dim--];
    };

    /**
     * @brief modifica la dimensione massima del Sistema_stellare
     * @param nuova dimensione massima
     */
    void reserve(int newLength){
        if(length==newLength) return;
        length= newLength;
        T* data= new T[length];
        dim= dim<length ? dim : length;
        for(auto i= 0; i<dim; i++) data[i]= ele[i];
        delete [] ele;
        ele= data;
    }


};

#endif // SISTEMA_STELLARE_H
