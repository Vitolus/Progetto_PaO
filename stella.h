#ifndef STELLA_H
#define STELLA_H
#include "corpo_celeste.h"

class Stella : public Corpo_celeste {
    float temperatura;
    std::string colore;
public:
    Stella();
    Stella(float, float, float= 1700);
    Stella(Stella&);
    virtual ~Stella();
    Stella& operator=(const Stella&);
    virtual float get_temperatura() const override;
    virtual std::string get_colore() const override;
    virtual Corpo_celeste* clone() override;
};

#endif // STELLA_H
