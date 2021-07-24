#ifndef SATELLITE_H
#define SATELLITE_H
#include "pianeta.h"

class Satellite : public Pianeta{
    Pianeta *pianetaOrbitato;
public:
    Satellite(float, float, bool, Pianeta&);
    Satellite(Satellite&);
    Satellite &operator=(const Satellite&);
    Pianeta *get_pianeta_orbitato() const;
    virtual ~Satellite();
};

#endif // SATELLITE_H
