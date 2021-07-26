#ifndef PIANETA_H
#define PIANETA_H
#include "corpo_celeste.h"

class Pianeta : public Corpo_celeste{
protected:
    bool tipo; //true=roccioso o false=gassoso
public:
    Pianeta(float, float, bool);
    Pianeta(Pianeta&);
    Pianeta &operator=(const Pianeta&);
    std::string get_tipo() const;
    virtual QVector<std::variant<float,bool,std::string>> get_data()const override;
    virtual ~Pianeta();
};

#endif // PIANETA_H
