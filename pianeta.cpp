#include "pianeta.h"

Pianeta::Pianeta() : Corpo_celeste(), tipo(true){}

Pianeta::Pianeta(QString n,float d,float f, bool t) : Corpo_celeste(n, d, f), tipo(t){}

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

bool Pianeta::is_equal(const Corpo_celeste& c)const{
    return (Corpo_celeste::is_equal(c) && ((c.get_tipo()=="roccioso" && tipo) || (c.get_tipo()=="gassoso" && !tipo)));
}

QString Pianeta::get_tipo()const{
    return tipo ? "roccioso" : "gassoso";
}

Corpo_celeste* Pianeta::clone(){
    return new Pianeta(*this);
}

QString Pianeta::type_name() const{
    return "Pianeta";
}
