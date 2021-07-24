#include "pianeta.h"

QString Pianeta::get_tipo() const{
    return tipo ? "roccioso" : "gassoso";
}

Pianeta::~Pianeta(){}

Pianeta::Pianeta(float d,float f, bool t) : Corpo_celeste(d, f, false){
    tipo= t;
}

Pianeta::Pianeta(Pianeta &p) : Corpo_celeste(p){
    if(p.get_tipo()=="roccioso") tipo= true;
    else tipo= false;
}

Pianeta &Pianeta::operator=(const Pianeta &p){
    if(p.get_tipo()=="roccioso") tipo= true;
    else tipo= false;
    return *this;
}
