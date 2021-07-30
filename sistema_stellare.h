#ifndef SISTEMA_STELLARE_H
#define SISTEMA_STELLARE_H
#include <cassert>
#include <QIterator>

template <class T>
class Sistema_stellare{
    int length;
    T *ele;
public:
    Sistema_stellare() : length(), ele(nullptr){}

    explicit Sistema_stellare(int l) : length(l){
        assert(length>=0);
        if(l>0) ele= new T[length];
    }

    Sistema_stellare(int l, const T &e= T()) : length(l), ele(e){}

    Sistema_stellare(const Sistema_stellare &s){
        length= s.length;
        ele= new T[length];
        for(auto i= 0; i<length; i++) ele[i]= s.ele[i];
    }

    Sistema_stellare(Sistema_stellare &&s){
        length= s.length;
        ele= s.ele;
        s.ele= nullptr;
        s.length= 0;
    }

    ~Sistema_stellare(){
        if(ele) delete [] ele;
    }

    Sistema_stellare &operator=(const Sistema_stellare &s){
        erase();
        length= s.length;
        ele= new T[length];
        for(auto i= 0; i<length; i++) ele[i]= s.ele[i];
    }

    Sistema_stellare &operator=(Sistema_stellare &&s){
        erase();
        length= s.length;
        ele= s.ele;
        s.ele= nullptr;
        s.length= 0;
    }

    void assign(int l, const T &data){
        erase();
        length= l;
        ele= new T[length];
        for(auto i= 0; i<length; i++) ele[i]= data;
    }

    T &at(int i){
        assert(i>=0 && i < length);
        return ele[i];
    }

    T &operator[](T i){
        assert(i>=0 && i < length);
        return ele[i];
    }

    T &front(){
        return ele[0];
    }

    T &back(){
        return ele[length-1];
    }

    T *data() noexcept{
        return ele;
    }

    const T *data() const noexcept{
        return ele;
    }

     QIterator<T> begin() noexcept{
        return QIterator(ele);
    }

    void erase(){
        delete [] ele;
        ele= nullptr;
        length= 0;
    }

    void resize(int newLength){
        if(length==newLength) return;
        if(newLength<=0){
            erase();
            return;
        }
        T* data= new T[newLength];
        if(length>0){
            int toCopy= newLength>length ? length : newLength;
            for(auto i= 0; i<toCopy; i++) data[i]= ele[i];
        }
        delete [] ele;
        ele= data;
        length= newLength;
    }
};

#endif // SISTEMA_STELLARE_H
