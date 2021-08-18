#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "gui.h"
#include "sistema_stellare.h"
#include "deep_ptr.h"
#include "corpo_celeste.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"

class Controller : public QObject{
    Q_OBJECT

    Gui* gui;
    QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>> sistemi;
public:
    Controller();
    Gui* get_gui();
public slots:
    void add_Corpo(QStringList);
signals:
};

#endif // CONTROLLER_H
