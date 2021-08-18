#ifndef SATELLITE_H
#define SATELLITE_H
#include "pianeta.h"

class Satellite : public Pianeta{
    const Pianeta* pianetaOrbitato;
public:
    Satellite();
    Satellite(QString, float, float, bool,const Pianeta* const);
    Satellite(Satellite&);
    virtual ~Satellite();
    Satellite& operator=(const Satellite&);
    virtual bool is_equal(const Corpo_celeste&)const override;
    virtual const Pianeta* get_pianeta_orbitato() const override;
    virtual Corpo_celeste* clone() override;
};

#endif // SATELLITE_H
