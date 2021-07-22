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
    virtual ~Corpo_celeste()= 0;
    float getDiametro() const;
    float getForzaGravita() const;
    bool getLuminoso() const;
};

#endif // CORPO_CELESTE_H
