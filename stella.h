#ifndef STELLA_H
#define STELLA_H
#include "corpo_celeste.h"

class Stella : public Corpo_celeste {
    float temperatura;
    QString colore;
public:
    Stella();
    Stella(QString, float, float, float= 1700);
    Stella(Stella&);
    virtual ~Stella();
    Stella& operator=(const Stella&);
    virtual bool is_equal(const Corpo_celeste&)const override;
    virtual float get_temperatura()const override;
    virtual QString get_colore()const override;
    virtual Corpo_celeste* clone()override;
    virtual QString type_name()const override;
};

#endif // STELLA_H
