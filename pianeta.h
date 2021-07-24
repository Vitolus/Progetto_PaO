#ifndef PIANETA_H
#define PIANETA_H
#include "corpo_celeste.h"

class Pianeta : virtual public Corpo_celeste{
protected:
    bool tipo; //true=roccioso o false=gassoso
public:
    Pianeta(float, float, bool);
    Pianeta(Pianeta&);
    Pianeta &operator=(const Pianeta&);
    QString get_tipo() const;
    virtual ~Pianeta();
};

#endif // PIANETA_H
