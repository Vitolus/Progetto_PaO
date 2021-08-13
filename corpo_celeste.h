#ifndef CORPO_CELESTE_H
#define CORPO_CELESTE_H
#include <string>
class Pianeta; /// forward declaration
class Corpo_celeste{
protected:
    float diametro;
    float forzaGravita;
    bool luminoso;

public:
    Corpo_celeste();
    Corpo_celeste(float,float, bool= false);
    Corpo_celeste(Corpo_celeste&);
    virtual ~Corpo_celeste();
    Corpo_celeste& operator=(const Corpo_celeste&);
    float get_diametro() const;
    float get_forza_gravita() const;
    bool get_luminoso() const;
    virtual float get_temperatura() const;
    virtual std::string get_colore() const;
    virtual std::string get_tipo() const;
    virtual const Pianeta* get_pianeta_orbitato() const;
    virtual Corpo_celeste* clone()= 0;
};

#endif // CORPO_CELESTE_H
