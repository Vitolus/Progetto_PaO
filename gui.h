#ifndef GUI_H
#define GUI_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "deep_ptr.h"
#include "corpo_celeste.h"
#include <QCheckBox>
#include <QDebug>

class Controller;
namespace Ui {
class Gui;
}

/*!
 * \brief La classe Gui rappresenza la view
 * \author Davide Vitagliano
 * \date Agosto 2021
 * \version v1
 */
class Gui : public QWidget{
    Q_OBJECT

    Ui::Gui* ui; //!<ui Puntatore alla Gui
    QTreeWidget* tree; //!<tree Rappresenta il database grafico
    Controller* controller; //!<controller Controller che gestisce la view

public:

    /*!
     * \brief Costruttore della Gui
     */
    explicit Gui(Controller*, QWidget* parent = nullptr);

    /*!
     * \brief Distruttore della Gui
     */
    ~Gui();
public slots:

    /*!
     * \brief Elimina li contenuto dei box dati della stella
     */
    void sclear();

    /*!
     * \brief Elimina li contenuto dei box dati del pianeta
     */
    void pclear();

    /*!
     * \brief Elimina li contenuto dei box dati del satellite
     */
    void saclear();

    /*!
     * \brief Aggiunge un sistema stellare contenente una stella al database grafico, o aggiunge un corpo celeste non stella a un sistema esistente
     */
    void add_data(const Deep_ptr<Corpo_celeste>,int= 0);

signals:

    /*!
     * \brief Segnale emesso quando i dati di un corpo celeste sono stati generati
     */
    void send_data(const QStringList&);

    /*!
     * \brief Segnale emesso quando un corpo celeste viene eliminato dal database grafico
     */
    void notify_remove(const QString, const QString);

private slots:
    /*!
     * \brief Crea una lista di stringhe che rappresentano i dati di una stella
     */
    void on_sSubmit_clicked();

    /*!
     * \brief Crea una lista di stringhe che rappresentano i dati di un pianeta
     */
    void on_pSubmit_clicked();

    /*!
     * \brief Crea una lista di stringhe che rappresentano i dati di un satellite
     */
    void on_saSubmit_clicked();

    /*!
     * \brief Elimina un sistema stellare dal database grafico se si doppio clicka su una stella o solo il pianeta o satellite altrimenti
     */
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
};

#endif // GUI_H
