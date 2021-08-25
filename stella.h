#ifndef STELLA_H
#define STELLA_H
#include "corpo_celeste.h"

/*!
 * \brief La classe Stella è una classe virtuale che rappresenta le informazioni di base di un Satellite.
 * \author Davide Vitagliano
 * \date Agosto 2021
 * \version v1
*/
class Stella : public Corpo_celeste {
    float temperatura; //!<temperatura Temperatura della Stella
    QString colore; //!<colore Colore della Stella basato sulla temperatura
public:

    /*!
     * \brief Costruttore di default
     */
    Stella();

    /*!
     * \brief Costruttore di Stella
     */
    Stella(QString, float, float, float= 1700);

    /*!
     * \brief Costruttore di copia
     */
    Stella(Stella&);

    /*!
     * \brief Distruttore di default
     */
    virtual ~Stella();

    /*!
     * \brief Operatore di assegnazione di copia
     * \return oggetto di invocazione
     */
    Stella& operator=(const Stella&);

    /*!
     * \brief Confronta l'oggetto di invocazione con un Corpo_celeste e verifica se sono uguali
     * \return true se uguali, false altrimenti
     */
    virtual bool is_equal(const Corpo_celeste&)const override;

    /*!
     * \brief Ritorna la temperatura della Stella
     * \return temperatura
     */
    virtual float get_temperatura()const override;

    /*!
     * \brief Ritorna la temperatura della Stella
     * \return colore
     */
    virtual QString get_colore()const override;

    /*!
     * \brief Ritorna una nuova copia dell'oggetto di invocazione
     * \return puntatore a un nuovo Stella
     */
    virtual Corpo_celeste* clone()override;

    /*!
     * \brief Ritorna il nome del tipo di oggetto come se si fosse eseguito typeid(this).name()
     * \return tipo dell'oggetto di invocazione
     */
    virtual QString type_name()const override;
};

#endif // STELLA_H
