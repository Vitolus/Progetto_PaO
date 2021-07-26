/*#include "deep_ptr.h"
template<class P>
Deep_ptr<P>::Deep_ptr() : ptr(nullptr){}

template<class P>
Deep_ptr<P>::Deep_ptr(P *v) : ptr(v){}

template<class P>
Deep_ptr<P>::Deep_ptr(P &v) : ptr(new P(v)){}

template<class P>
Deep_ptr<P>::Deep_ptr(Deep_ptr &p){
    P *temp= new P(*(p.ptr));
    std::swap(temp, ptr);
    delete temp;
}

template<class P>
Deep_ptr<P> &Deep_ptr<P>::operator=(const Deep_ptr &p){
    P *temp= new P(*(p.ptr));
    std::swap(temp, ptr);
    delete temp;
    return *this;
}

template<class P>
Deep_ptr<P>::~Deep_ptr(){
    delete ptr;
}*/
