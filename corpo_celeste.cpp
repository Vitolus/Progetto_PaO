#include "corpo_celeste.h"

float Corpo_celeste::get_diametro() const{
    return diametro;
}

float Corpo_celeste::get_forza_gravita() const{
    return forzaGravita;
}


bool Corpo_celeste::get_luminoso() const{
    return luminoso;
}

Corpo_celeste::Corpo_celeste(float d, float f, bool l){
    diametro= d;
    forzaGravita= f;
    luminoso= l;
}

Corpo_celeste::Corpo_celeste(Corpo_celeste &c){
    diametro= c.get_diametro();
    forzaGravita= c.get_forza_gravita();
    luminoso= c.get_luminoso();
}

Corpo_celeste &Corpo_celeste::operator=(const Corpo_celeste &c){
    diametro= c.get_diametro();
    forzaGravita= c.get_forza_gravita();
    luminoso= c.get_luminoso();
    return *this;
}

Corpo_celeste::~Corpo_celeste(){}
