#include "corpo_celeste.h"

Corpo_celeste::Corpo_celeste(){
    diametro= 0;
    forzaGravita= 0;
    nome= "";
}

Corpo_celeste::Corpo_celeste(QString n, float d, float f){
    diametro= d;
    forzaGravita= f;
    nome= n;
}

Corpo_celeste::Corpo_celeste(Corpo_celeste &c){
    diametro= c.get_diametro();
    forzaGravita= c.get_forza_gravita();
    nome= c.get_nome();
}

Corpo_celeste::~Corpo_celeste(){}

Corpo_celeste& Corpo_celeste::operator=(const Corpo_celeste& c){
    diametro= c.get_diametro();
    forzaGravita= c.get_forza_gravita();
    nome= c.get_nome();
    return *this;
}

bool Corpo_celeste::is_equal(const Corpo_celeste& c)const{
    return (nome==c.get_nome()&& diametro==c.get_diametro() && forzaGravita==c.get_forza_gravita());
}

QString Corpo_celeste::get_nome() const{
    return nome;
}

float Corpo_celeste::get_diametro() const{
    return diametro;
}

float Corpo_celeste::get_forza_gravita() const{
    return forzaGravita;
}

float Corpo_celeste::get_temperatura() const{
    return 0;
}

QString Corpo_celeste::get_colore() const{
    return "";
}

QString Corpo_celeste::get_tipo() const{
return "";
}

const Pianeta* Corpo_celeste::get_pianeta_orbitato() const{
    return nullptr;
}
