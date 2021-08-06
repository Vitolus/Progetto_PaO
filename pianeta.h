#ifndef PIANETA_H
#define PIANETA_H
#include "corpo_celeste.h"

class Pianeta : public Corpo_celeste{
protected:
    bool tipo; //true=roccioso o false=gassoso
public:
    Pianeta();
    Pianeta(float, float, bool);
    Pianeta(Pianeta&);
    virtual ~Pianeta();
    Pianeta &operator=(const Pianeta&);
    virtual std::string get_tipo() const override;
    virtual Corpo_celeste* clone() override;
};

#endif // PIANETA_H
