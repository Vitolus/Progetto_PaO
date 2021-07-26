#include "pianeta.h"

std::string Pianeta::get_tipo() const{
    return tipo ? "roccioso" : "gassoso";
}

QVector<std::variant<float, bool, std::string>> Pianeta::get_data() const{
    QVector<std::variant<float, bool, std::string>> data;
    data.push_back(this->get_diametro());
    data.push_back(this->get_forza_gravita());
    data.push_back(this->get_luminoso());
    data.push_back(this->get_tipo());
    return data;
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
