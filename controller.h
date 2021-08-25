#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QLocale>
#include "gui.h"
#include "sistema_stellare.h"
#include "corpo_celeste.h"
#include "deep_ptr.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"

/*!
 * \brief La classe Controller gestisce la comunicazione tra il model e la view.
 * Controller è il tramite per gli slots e i segnali tra il model e la view.
 * \author Davide Vitagliano
 * \date Agosto 2021
 * \version v1
*/
class Controller : public QObject{
    Q_OBJECT

    Gui* gui; //!<gui Gui collegata al Controller
    QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>> sistemi;//!<sistemi Vettore rappresentante il modello
public:
    /*!
     * \brief Costruttore del Controller
     */
    Controller();

    /*!
     * \brief Connette gli slots e i segnali tra model e view
     */
    void setController();

    /*!
     * \brief Ritorna un puntatore alla Gui gestita dal Controller
     * \return puntatore a gui
     */
    Gui* get_gui();  
public slots:

    /*!
     * \brief Aggiunge un Sistema_stellare contenente una Stella a sistemi, o aggiunge un Copro_celeste non Stella a un sistema esistente in sistemi
     */
    void add_corpo(const QStringList&);

    /*!
     * \brief Rimuove un Sistema_stellare da sistemi se riceve una Stella, o rimuove un Copro_celeste non Stella da un sistema esistente in sistemi
     */
    void remove_corpo(const QString, const QString);

signals:

    /*!
     * \brief Segnale emesso quando un Corpo_celeste viene aggiunto a sistemi
     */
    void show_corpo(const Deep_ptr<Corpo_celeste>, int= 0);
};

#endif // CONTROLLER_H
