#ifndef SATELLITE_H
#define SATELLITE_H
#include "pianeta.h"

class Satellite : public Pianeta{
    Pianeta *pianetaOrbitato;
public:
    Satellite();
    Satellite(float, float, bool, Pianeta&);
    Satellite(Satellite&);
    Satellite &operator=(const Satellite&);
    virtual Pianeta *get_pianeta_orbitato() const override;
    virtual ~Satellite();
};

#endif // SATELLITE_H
