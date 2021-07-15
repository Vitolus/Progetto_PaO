#ifndef DADO_H
#define DADO_H
#include <QVector>

class Dado{
    unsigned short nFacce;
    QVector<unsigned short> valori;
    public:
        Dado(unsigned short);
};

#endif // DADO_H
