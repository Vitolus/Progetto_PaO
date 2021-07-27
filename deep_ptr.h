#ifndef DEEP_PTR_H
#define DEEP_PTR_H
#include <algorithm>
#include "corpo_celeste.h"
template <class P>
class Deep_ptr{
    P *ptr;
    void cleanup(){
        if(ptr != nullptr) delete ptr;
    }
public:
    constexpr Deep_ptr() noexcept : ptr(nullptr){}

    constexpr Deep_ptr(std::nullptr_t) noexcept : ptr(nullptr){}

    explicit Deep_ptr(P* p) noexcept: ptr(p){}

    Deep_ptr(const Deep_ptr & p)= delete;

    Deep_ptr(Deep_ptr && p){
        this->ptr= p.ptr;
        p.ptr= nullptr;
    }

    ~Deep_ptr(){
        cleanup();
    }

    Deep_ptr& operator=(const Deep_ptr & p) = delete;

    void operator=(Deep_ptr && p){
        cleanup();
        this->ptr= p.ptr;
        p.ptr= nullptr;
    }

    P* operator->(){
        return this->ptr;
    }

    P& operator*(){
        return *(this->ptr);
    }
};

#endif // DEEP_PTR_H
