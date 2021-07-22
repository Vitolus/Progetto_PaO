#include "stella.h"

float Stella::getTemperatura() const{
    return temperatura;
}

const QString &Stella::getColore() const{
    return colore;
}

Stella::Stella(float d,float f, float t) : Corpo_celeste(d, f, true){
    temperatura= t;
    if(temperatura<=1700) colore= "rossa";
    else if(temperatura<=3000) colore= "arancione";
    else if(temperatura<=6000) colore= "gialla";
    else colore= "bianca";
}
