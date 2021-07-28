#ifndef DEEP_PTR_H
#define DEEP_PTR_H
#include <algorithm>
#include "corpo_celeste.h"
template <class P>
class Deep_ptr{
    P *ptr;
public:
    constexpr Deep_ptr() noexcept : ptr(nullptr){}

    constexpr Deep_ptr(std::nullptr_t) noexcept : ptr(nullptr){}

    explicit Deep_ptr(P* p) noexcept: ptr(p){}

    Deep_ptr(Deep_ptr && p) noexcept{
        ptr= p.ptr;
        p.ptr= nullptr;
    }

    ~Deep_ptr(){
        if(ptr) delete ptr;
    }

    Deep_ptr &operator=(Deep_ptr && p) noexcept{
        ptr= p.ptr;
        p.ptr= nullptr;
    }

    Deep_ptr &operator=(std::nullptr_t) noexcept{
        reset(nullptr);
    }

    P* release() noexcept{
        if(ptr){
            P* temp= ptr;
            ptr= nullptr;
            return temp;
        }
    }

    void reset(P* p= P()) noexcept{
        P* old= ptr;
        ptr= p;
        if(old) delete old;
    }

    void swap(Deep_ptr &p) noexcept{
        P* temp= ptr;
        ptr= p;
        p= temp;
    }

    P* get()const noexcept{
        return ptr;
    }

    typename std::add_lvalue_reference<P>::type operator*()const{
        return *ptr;
    }

    P* operator->()const noexcept{
        return ptr;
    }
};

#endif // DEEP_PTR_H
