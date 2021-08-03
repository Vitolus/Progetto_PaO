#ifndef SISTEMA_STELLARE_H
#define SISTEMA_STELLARE_H
#include <cassert>
#include <QIterator>

template <class T>
class Sistema_stellare{
    int length;
    int dim;
    T *ele;
public:

    Sistema_stellare() : length(), ele(nullptr){}

    /**
     * @brief costruisce Sistema_stellare vuoto con lunghezza l
     * @param l lunghezza
     */
    explicit Sistema_stellare(int l) : length(l){
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
     */
    Sistema_stellare(Sistema_stellare &&s){
        length= s.length;
        dim= length;
        ele= s.ele;
        s.ele= nullptr;
        s.length= 0;
        s.dim= 0;
    }

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
     */
    Sistema_stellare &operator=(Sistema_stellare &&s){
        erase();
        length= s.length;
        dim= length;
        ele= s.ele;
        s.ele= nullptr;
        s.length= 0;
        s.dim= 0;
    }

    /**
     * @brief accede all'oggetto specificato con controllo limiti
     * @param i posizione dell'elemento
     * @return referenza elemento richiesto
     */
    T &at(int i){
        assert(i>=0 && i < dim);
        return ele[i];
    }

    T &operator[](T i){
        assert(i>=0 && i < dim);
        return ele[i];
    }

    /**
     * @brief accede al primo elemento
     * @return referenza primo elemento
     */
    T &front(){
        return ele[0];
    }

    /**
     * @brief accede all'ultimo elemento
     * @return referenza ultimo elemento
     */
    T &back(){
        return ele[dim-1];
    }

    /**
     * @brief accesso diretto all'array sottostante
     * @return puntatore primo elemento
     */
    T *data() noexcept{
        return ele;
    }

    /**
     * @brief accesso diretto all'array sottostante costantemente
     * @return puntatore al primo elemento
     */
    const T *data() const noexcept{
        return ele;
    }

    /**
      * @brief ritorna un iteratore all'inizio dell'array
      * @return iteratore al primo elemento
      */
     QIterator<T> begin() noexcept{
        return QIterator(ele);
    }

     /**
      * @brief ritorna un iteratore costante all'inizio dell'array
      * @return iteratore costante al primo elemento
      */
     QConstIterator<T> begin() const noexcept{
         return QConstIterator(ele);
     }

     /**
      * @brief ritorna un iteratore alla fine dell'array
      * @return iteratore all'elemento successivo all'ultimo
      */
     QIterator<T> end() noexcept{
         return QIterator(ele[dim]);
     }

     /**
      * @brief ritorna un iteratore costante alla fine dell'array
      * @return iteratore costante all'elemento successivo all'ultimo
      */
     QConstIterator<T> end() const noexcept{
         return QConstIterator(ele[dim]);
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
     int size() const noexcept {
         return dim;
     }

     /**
      * @brief ritorna dimensione massima
      * @return length
      */
     int capacity() const noexcept{
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
    void erase(int pos){
        assert(pos>=0 && pos < dim);
        delete ele[pos];
        dim= dim-1;
    }

    /**
     * @brief modifica la dimensione massima del Sistema_stellare
     * @param nuova dimensione massima
     */
    void resize(int newLength){
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
