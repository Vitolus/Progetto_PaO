#include "pianeta.h"

Pianeta::Pianeta() : Corpo_celeste(), tipo(true){}

Pianeta::Pianeta(float d,float f, bool t) : Corpo_celeste(d, f, false), tipo(t){}

Pianeta::Pianeta(Pianeta& p) : Corpo_celeste(p){
    if(p.get_tipo()=="roccioso") tipo= true;
    else tipo= false;
}

Pianeta::~Pianeta(){}

Pianeta& Pianeta::operator=(const Pianeta& p){
    Corpo_celeste::operator=(p);
    if(p.get_tipo()=="roccioso") tipo= true;
    else tipo= false;
    return *this;
}

std::string Pianeta::get_tipo() const{
    return tipo ? "roccioso" : "gassoso";
}

Corpo_celeste* Pianeta::clone(){
    return new Pianeta(*this);
}
