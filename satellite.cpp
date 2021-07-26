#include "satellite.h"

Pianeta *Satellite::get_pianeta_orbitato() const{
    return pianetaOrbitato;
}

Satellite::~Satellite(){
    delete pianetaOrbitato;
}

Satellite::Satellite(float d, float f, bool t, Pianeta& p) : Pianeta(d, f, t){
    pianetaOrbitato= new Pianeta(p);
}

Satellite::Satellite(Satellite &s) : Pianeta(s){
    pianetaOrbitato= s.get_pianeta_orbitato();
}

Satellite &Satellite::operator=(const Satellite &s){
    pianetaOrbitato= s.get_pianeta_orbitato();
    return *this;
}
