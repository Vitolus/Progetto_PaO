#ifndef GUI_H
#define GUI_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class Controller;
namespace Ui {
class Gui;
}
class Gui : public QWidget{
    Q_OBJECT

    Ui::Gui* ui;
    QTreeWidget* tree;
    QTreeWidgetItem* sistemi;
    Controller* controller;
public:
    explicit Gui(Controller*, QWidget* parent = nullptr);
    ~Gui();
public slots:
    QStringList on_sSubmit_clicked();
    QStringList on_pSubmit_clicked();
    QStringList on_saSubmit_clicked();

};

#endif // GUI_H
