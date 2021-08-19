#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QLocale>
#include "gui.h"
#include "sistema_stellare.h"
#include "deep_ptr.h"
#include "corpo_celeste.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"
#include <iostream>

class Controller : public QObject{
    Q_OBJECT

    Gui* gui;
    QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>> sistemi;
public:
    Controller();
    void setController();
    Gui* get_gui();  
public slots:
    void add_Corpo(QStringList);
signals:
    void show_corpo(QString, Deep_ptr<Corpo_celeste>);
};

#endif // CONTROLLER_H
