#ifndef DEEP_PTR_H
#define DEEP_PTR_H
#include <utility>

template <class T>
/*!
 * \brief La classe Deep_ptr implementa un template di puntatore polimorfo di un oggetto di tipo T
 * \author Davide Vitagliano
 * \date Agosto 2021
 * \version v1
 */
class Deep_ptr{
    typedef std::size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;

    pointer ptr;//!<ptr Puntatore all'oggetto di tipo T
public:

    /*!
     * \brief Costruttore di Deep_ptr
     */
    Deep_ptr(pointer =nullptr);

    /*!
     * \brief Costruttore di copia profonda
     */
    Deep_ptr(const Deep_ptr&);

    /*!
     * \brief Distruttore profondo
     */
    ~Deep_ptr();

    /*!
     * \brief Operatore di assegnazione di copia profonda
     * \return oggetto di invocazione
     */
    Deep_ptr& operator=(const Deep_ptr&);

    /*!
     * \brief Operatore di assegnazione di nullptr
     * \return oggetto di invocazione
     */
    Deep_ptr& operator=(std::nullptr_t);

    /*!
     * \brief Operatore di deferenziazione
     * \return referenza all'oggetto puntato dall'oggetto di invocazione
     */
    reference operator*()const;

    /*!
     * \brief Operatore di freccia
     * \return puntatore (deferenziato) all'oggetto di invocazione
     */
    pointer operator->() const;

    /*!
     * \brief Operatore di uguaglianza
     * \return true se uguali, false altrimenti
     */
    bool operator==(const Deep_ptr&) const;

    /*!
     * \brief Operatore di disuguaglianza
     * \return true se diversi, false altrimenti
     */
    bool operator!=(const Deep_ptr&) const;

    /*!
     * \brief Operatore di maggioranza
     * \return true se maggiore, false altrimenti
     */
    bool operator>(const Deep_ptr&) const;

    /*!
     * \brief Operatore di maggioranza o uguaglianza
     * \return true se maggiore o uguale, false altrimenti
     */
    bool operator>=(const Deep_ptr&) const;

    /*!
     * \brief Operatore di minoranza
     * \return true se minore, false altrimenti
     */
    bool operator<(const Deep_ptr&) const;

    /*!
     * \brief Operatore di minoranza o uguaglianza
     * \return true se minore o uguale, false altrimenti
     */
    bool operator<=(const Deep_ptr&) const;

    /*!
     * \brief Operatore di conversione di tipo
     */
    operator pointer() const;

    /*!
     * \brief Ritorna il puntatore di Deep_ptr
     * \return ptr
     */
    pointer get_pointer()const;
};

template <class T>
Deep_ptr<T>::Deep_ptr(pointer p): ptr(p){}

template <class T>
Deep_ptr<T>::Deep_ptr(const Deep_ptr& deep){
    if(!deep) ptr=nullptr;
    else ptr= deep.ptr->clone();
}

template <class T>
Deep_ptr<T>::~Deep_ptr(){
    if(ptr) delete ptr;
}

template <class T>
Deep_ptr<T>& Deep_ptr<T>::operator=(const Deep_ptr& deep){
    if(this==&deep) return *this;
    if(ptr) delete ptr;
    ptr = deep.ptr->clone();
    return *this;
}

template <class T>
Deep_ptr<T>& Deep_ptr<T>::operator=(std::nullptr_t){
    if(ptr) delete ptr;
    ptr= nullptr;
    return *this;
}

template <class T>
typename Deep_ptr<T>::reference Deep_ptr<T>::operator*()const{
    return *ptr;
}

template <class T>
typename Deep_ptr<T>::pointer Deep_ptr<T>::operator->() const{
       return ptr;
}

template <class T>
bool Deep_ptr<T>::operator==(const Deep_ptr& dptr) const{
    return *ptr==*(dptr.ptr);
}

template <class T>
bool Deep_ptr<T>::operator!=(const Deep_ptr& dptr) const{
    return *ptr!=*(dptr.ptr);
}

template<class T>
bool Deep_ptr<T>::operator<(const Deep_ptr& dptr) const{
    return *ptr<*(dptr.ptr);
}

template<class T>
bool Deep_ptr<T>::operator>(const Deep_ptr& dptr) const{
    return *ptr>*(dptr.ptr);
}

template<class T>
Deep_ptr<T>::operator pointer() const{
    return ptr;
}

template<class T>
typename Deep_ptr<T>::pointer Deep_ptr<T>::get_pointer() const{
    return ptr;
}


#endif // DEEP_PTR_H
