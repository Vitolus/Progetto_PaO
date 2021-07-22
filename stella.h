#ifndef STELLA_H
#define STELLA_H
#include "corpo_celeste.h"
#include <QString>

class Stella : virtual public Corpo_celeste {
    float temperatura;
    QString colore;
public:
    Stella(float, float, float= 1700);
    float getTemperatura() const;
    const QString &getColore() const;
};

#endif // STELLA_H
