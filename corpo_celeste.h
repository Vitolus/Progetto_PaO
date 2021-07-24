#ifndef CORPO_CELESTE_H
#define CORPO_CELESTE_H
#include <QVector>

class Corpo_celeste{
protected:
    float diametro;
    float forzaGravita;
    bool luminoso;

public:
    Corpo_celeste(float,float, bool= false);
    Corpo_celeste(Corpo_celeste&);
    Corpo_celeste &operator=(const Corpo_celeste&);
    float get_diametro() const;
    float get_forza_gravita() const;
    bool get_luminoso() const;
    virtual ~Corpo_celeste()= 0;

};

#endif // CORPO_CELESTE_H
