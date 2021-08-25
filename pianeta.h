#ifndef PIANETA_H
#define PIANETA_H
#include "corpo_celeste.h"

/*!
 * \brief La classe Pianeta è una classe virtuale che rappresenta le informazioni di base di un Pianeta.
 * \author Davide Vitagliano
 * \date Agosto 2021
 * \version v1
*/
class Pianeta : public Corpo_celeste{
protected:
    bool tipo; //!<tipo true = roccioso, false = gassoso
public:

    /*!
     * \brief Costruttore di default
     */
    Pianeta();

    /*!
     * \brief Costruttore di Pianeta
     */
    Pianeta(QString, float, float, bool);

    /*!
     * \brief Costruttore di copia
     */
    Pianeta(Pianeta&);

    /*!
     * \brief Distruttore di default
     */
    virtual ~Pianeta();

    /*!
     * \brief Operatore di assegnazione di copia
     * \return oggetto di invocazione
     */
    Pianeta &operator=(const Pianeta&);

    /*!
     * \brief Confronta l'oggetto di invocazione con un Corpo_celeste e verifica se sono uguali
     * \return true se uguali, false altrimenti
     */
    virtual bool is_equal(const Corpo_celeste&)const override;

    /*!
     * \brief Ritorna il tipo convertito in stringa
     * \return tipo
     */
    virtual QString get_tipo()const override;

    /*!
     * \brief Ritorna una nuova copia dell'oggetto di invocazione
     * \return puntatore a un nuovo Pianeta
     */
    virtual Corpo_celeste* clone()override;

    /*!
     * \brief Ritorna il nome del tipo di oggetto come se si fosse eseguito typeid(this).name()
     * \return tipo dell'oggetto di invocazione
     */
    virtual QString type_name()const override;
};

#endif // PIANETA_H
