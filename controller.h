#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QLocale>
#include "gui.h"
#include "model.h"

class Controller : public QObject{
    Q_OBJECT

    Gui* gui;
    Model model;
public:
    Controller();
    void setController();
    Gui* get_gui();  
public slots:
    void add_Corpo(const QStringList&);
signals:
    void show_corpo(QString, Deep_ptr<Corpo_celeste>);
};

#endif // CONTROLLER_H
