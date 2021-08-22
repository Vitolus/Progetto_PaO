#ifndef GUI_H
#define GUI_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "deep_ptr.h"
#include "corpo_celeste.h"

class Controller;
namespace Ui {
class Gui;
}
class Gui : public QWidget{
    Q_OBJECT

    Ui::Gui* ui;
    QTreeWidget* tree;
    Controller* controller;
public:
    explicit Gui(Controller*, QWidget* parent = nullptr);
    ~Gui();
public slots:
    void on_sSubmit_clicked();
    void on_pSubmit_clicked();
    void on_saSubmit_clicked();
    void sclear();
    void pclear();
    void saclear();
    void add_data(const Deep_ptr<Corpo_celeste>*,int= 0);
signals:
    void send_data(const QStringList&);
};

#endif // GUI_H
