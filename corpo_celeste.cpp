#include "corpo_celeste.h"

float Corpo_celeste::getDiametro() const{
    return diametro;
}

float Corpo_celeste::getForzaGravita() const{
    return forzaGravita;
}


bool Corpo_celeste::getLuminoso() const{
    return luminoso;
}

Corpo_celeste::Corpo_celeste(float d, float f, bool l){
    diametro= d;
    forzaGravita= f;
    luminoso= l;
}

Corpo_celeste::~Corpo_celeste(){}
