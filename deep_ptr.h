#ifndef DEEP_PTR_H
#define DEEP_PTR_H
#include <algorithm>
#include "corpo_celeste.h"
template <class P>
class Deep_ptr{
    P *ptr;
public:
    Deep_ptr() : ptr(nullptr){}

    Deep_ptr(P *v) : ptr(v){}

    Deep_ptr(P &v) : ptr(new P(v)){}

    Deep_ptr(Deep_ptr &p){
        P *temp= new P(*(p.ptr));
        std::swap(temp, ptr);
        delete temp;
    }

    Deep_ptr<P> &operator=(const Deep_ptr &p){
        P *temp= new P(*(p.ptr));
        std::swap(temp, ptr);
        delete temp;
        return *this;
    }

    P *operator->(){
        return *ptr;
    }

    P *operator*(){
        return *ptr;
    }

    ~Deep_ptr(){
        delete ptr;
    }
};

#endif // DEEP_PTR_H
