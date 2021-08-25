#ifndef SATELLITE_H
#define SATELLITE_H
#include "pianeta.h"

/*!
 * \brief La classe Satellite è una classe virtuale che rappresenta le informazioni di base di un Satellite.
 * \author Davide Vitagliano
 * \date Agosto 2021
 * \version v1
*/
class Satellite : public Pianeta{
    const Pianeta* pianetaOrbitato;//!<pianetaOrbitato Puntatore a il Pianeta orbitato dal Satellite
public:

    /*!
     * \brief Costruttore di Default
     */
    Satellite();

    /*!
     * \brief Costruttore di Pianeta
     */
    Satellite(QString, float, float, bool,const Pianeta* const);

    /*!
     * \brief Costruttore di copia
     */
    Satellite(Satellite&);

    /*!
     * \brief Distruttore di default
     */
    virtual ~Satellite();

    /*!
     * \brief Operatore di assegnazione di copia
     * \return oggetto di invocazione
     */
    Satellite& operator=(const Satellite&);

    /*!
     * \brief Confronta l'oggetto di invocazione con un Corpo_celeste e verifica se sono uguali
     * \return true se uguali, false altrimenti
     */
    virtual bool is_equal(const Corpo_celeste&)const override;

    /*!
     * \brief Ritorna il Pianeta che viene orbitato dal Satellite
     * \return pianetaOrbitato
     */
    virtual const Pianeta* get_pianeta_orbitato() const override;

    /*!
     * \brief Ritorna una nuova copia dell'oggetto di invocazione
     * \return puntatore a un nuovo Satellite
     */
    virtual Corpo_celeste* clone() override;

    /*!
     * \brief Ritorna il nome del tipo di oggetto come se si fosse eseguito typeid(this).name()
     * \return tipo dell'oggetto di invocazione
     */
    virtual QString type_name()const override;
};

#endif // SATELLITE_H
