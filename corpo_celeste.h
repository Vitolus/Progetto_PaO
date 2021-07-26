#ifndef CORPO_CELESTE_H
#define CORPO_CELESTE_H
#include <QVector>

class Corpo_celeste{
protected:
    float diametro;
    float forzaGravita;
    bool luminoso;

public:
    Corpo_celeste(float,float, bool= false);
    Corpo_celeste(Corpo_celeste&);
    Corpo_celeste &operator=(const Corpo_celeste&);
    float get_diametro() const;
    float get_forza_gravita() const;
    bool get_luminoso() const;
    virtual QVector<std::variant<float,bool,std::string>> get_data() const= 0;
    virtual ~Corpo_celeste();

};

#endif // CORPO_CELESTE_H
