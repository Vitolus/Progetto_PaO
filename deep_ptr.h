#ifndef DEEP_PTR_H
#define DEEP_PTR_H
#include <algorithm>
#include "corpo_celeste.h"
template <class P>
class Deep_ptr{
    typedef std::size_t size_type;
    typedef P value_type;
    typedef P& reference;
    typedef P* pointer;
    typedef std::ptrdiff_t difference_type;

    pointer ptr;
public:
    constexpr Deep_ptr() noexcept : ptr(nullptr){}

    constexpr Deep_ptr(std::nullptr_t) noexcept : ptr(nullptr){}

    explicit Deep_ptr(pointer p) noexcept: ptr(p){}

    /**
     * @brief move constructor
     * @param p
     */
    Deep_ptr(Deep_ptr && p) noexcept{
        ptr= p.ptr;
        p.ptr= nullptr;
    }

    ~Deep_ptr(){
        if(ptr) delete ptr;
    }

    /**
     * @brief move assignment operator
     * @param p
     * @return nuovo Deep_ptr (*this)
     */
    Deep_ptr &operator=(Deep_ptr && p) noexcept{
        ptr= p.ptr;
        p.ptr= nullptr;
        return *this;
    }

    Deep_ptr &operator=(std::nullptr_t) noexcept{
        reset(nullptr);
    }

    /**
     * @brief annulla puntatore
     * @return oggetto puntato
     */
    pointer release() noexcept{
        if(ptr){
            pointer temp= ptr;
            ptr= nullptr;
            return temp;
        }
    }

    /**
     * @brief riassegna puntatore eliminando vecchio
     * @param nuovo puntatore
     */
    void reset(pointer p= P()) noexcept{
        pointer old= ptr;
        ptr= p;
        if(old) delete old;
    }

    /**
     * @brief inverte puntatori
     * @param puntatore da invertire
     */
    void swap(Deep_ptr &p) noexcept{
        pointer temp= ptr;
        ptr= p;
        p= temp;
    }

    /**
     * @brief ritorna puntatore
     * @return puntatore oggetto
     */
    pointer get()const noexcept{
        return ptr;
    }

    typename std::add_lvalue_reference<P>::type operator*()const{
        return *ptr;
    }

    pointer operator->()const noexcept{
        return ptr;
    }
};

#endif // DEEP_PTR_H
