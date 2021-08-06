#include "satellite.h"

Satellite::Satellite() : Pianeta(){
    pianetaOrbitato= nullptr;
}

Satellite::Satellite(float d, float f, bool t,const Pianeta* p) : Pianeta(d, f, t){
    pianetaOrbitato= p;
}

Satellite::Satellite(Satellite &s) : Pianeta(s){
    pianetaOrbitato= s.get_pianeta_orbitato();
}

Satellite::~Satellite(){
    pianetaOrbitato= nullptr;
}

Satellite &Satellite::operator=(const Satellite &s){
    Corpo_celeste::operator=(s);
    pianetaOrbitato= s.get_pianeta_orbitato();
    return *this;
}

const Pianeta* Satellite::get_pianeta_orbitato() const{
    return pianetaOrbitato;
}

Corpo_celeste* Satellite::clone(){
    return new Satellite(*this);
}
