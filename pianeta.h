#ifndef PIANETA_H
#define PIANETA_H
#include "corpo_celeste.h"

class Pianeta : public Corpo_celeste{
protected:
    bool tipo; //true=roccioso o false=gassoso
public:
    Pianeta();
    Pianeta(QString, float, float, bool);
    Pianeta(Pianeta&);
    virtual ~Pianeta();
    Pianeta &operator=(const Pianeta&);
    virtual bool is_equal(const Corpo_celeste&)const override;
    virtual QString get_tipo()const override;
    virtual Corpo_celeste* clone()override;
    virtual QString type_name()const override;
};

#endif // PIANETA_H
