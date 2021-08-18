#ifndef CORPO_CELESTE_H
#define CORPO_CELESTE_H
#include <QString>
class Pianeta; /// forward declaration
class Corpo_celeste{
protected:
    QString nome;
    float diametro;
    float forzaGravita;

public:
    Corpo_celeste();
    Corpo_celeste(QString, float,float);
    Corpo_celeste(Corpo_celeste&);
    virtual ~Corpo_celeste();
    Corpo_celeste& operator=(const Corpo_celeste&);
    virtual bool is_equal(const Corpo_celeste&)const;
    QString get_nome()const;
    float get_diametro()const;
    float get_forza_gravita()const;
    virtual float get_temperatura()const;
    virtual QString get_colore()const;
    virtual QString get_tipo()const;
    virtual const Pianeta* get_pianeta_orbitato()const;
    virtual Corpo_celeste* clone()= 0;
};

#endif // CORPO_CELESTE_H
