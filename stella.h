#ifndef STELLA_H
#define STELLA_H
#include "corpo_celeste.h"
#include <QString>

class Stella : virtual public Corpo_celeste {
    float temperatura;
    QString colore;
public:
    Stella(float, float, float= 1700);
    Stella(Stella &);
    Stella &operator=(const Stella &);
    float get_temperatura() const;
    const QString &get_colore() const;
    virtual ~Stella();
};

#endif // STELLA_H
