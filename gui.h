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
    void on_sSubmit_clicked();
    void on_pSubmit_clicked();
    void on_saSubmit_clicked();
    void sclear();
    void pclear();
    void saclear();
    void add_data(const QStringList&);
signals:
    void send_data(const QStringList&);
};

#endif // GUI_H
