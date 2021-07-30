#ifndef STELLA_H
#define STELLA_H
#include "corpo_celeste.h"

class Stella : public Corpo_celeste {
    float temperatura;
    std::string colore;
public:
    Stella();
    Stella(float, float, float= 1700);
    Stella(Stella &);
    Stella &operator=(const Stella &);
    virtual float get_temperatura() const override;
    virtual std::string get_colore() const override;
    virtual QVector<std::variant<float,bool,std::string>> get_data() const override;
    virtual ~Stella();
};

#endif // STELLA_H
