#include "satellite.h"

Satellite::Satellite() : Pianeta(){
    pianetaOrbitato= nullptr;
}

Satellite::Satellite(QString n, float d, float f, bool t ,const Pianeta* p) : Pianeta(n, d, f, t){
    pianetaOrbitato= p;
}

Satellite::Satellite(Satellite &s) : Pianeta(s){
    pianetaOrbitato= s.get_pianeta_orbitato();
}

Satellite::~Satellite(){
    pianetaOrbitato= nullptr;
}

Satellite &Satellite::operator=(const Satellite &s){
    Pianeta::operator=(s);
    pianetaOrbitato= s.get_pianeta_orbitato();
    return *this;
}

bool Satellite::is_equal(const Corpo_celeste& c)const{
    return (Pianeta::is_equal(c) && pianetaOrbitato==c.get_pianeta_orbitato());
}

const Pianeta* Satellite::get_pianeta_orbitato()const{
    return pianetaOrbitato;
}

Corpo_celeste* Satellite::clone(){
    return new Satellite(*this);
}

QString Satellite::type_name() const{
    return "Satellite";
}
