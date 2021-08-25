#include "stella.h"

Stella::Stella() : Corpo_celeste(), temperatura(0), colore(""){}

Stella::Stella(QString n, float d,float f, float t) : Corpo_celeste(n, d, f), temperatura(t){
    if(temperatura>=9000) colore= "azzurra";
    else if(temperatura>=6000) colore= "bianca";
    else if(temperatura>=4600) colore= "gialla";
    else if(temperatura>=3200) colore= "arancione";
    else colore= "rossa";
}

Stella::Stella(Stella& s) : Corpo_celeste(s), temperatura(s.get_temperatura()), colore(s.get_colore()){}

Stella::~Stella(){}

Stella& Stella::operator=(const Stella& s){
    Corpo_celeste::operator=(s);
    temperatura= s.get_temperatura();
    colore= s.get_colore();
    return *this;
}

bool Stella::is_equal(const Corpo_celeste& c)const{
    return (Corpo_celeste::is_equal(c) && temperatura==c.get_temperatura() && colore==c.get_colore());
}

float Stella::get_temperatura()const{
    return temperatura;
}

QString Stella::get_colore()const{
    return colore;
}

Corpo_celeste* Stella::clone(){
    return new Stella(*this);
}

QString Stella::type_name() const{
    return "Stella";
}
