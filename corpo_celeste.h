#ifndef CORPO_CELESTE_H
#define CORPO_CELESTE_H
#include <QString>
class Pianeta; //! forward declaration

/*!
 * \brief La classe Corpo_celeste è una classe virtuale astratta che rappresenta le informazioni di base di un corpo celeste (stella, pianeta o satellite).
 * \author Davide Vitagliano
 * \date Agosto 2021
 * \version v1
*/
class Corpo_celeste{
protected:
    QString nome; //!<nome Nome del Corpo_celeste
    float diametro; //!<diametro Diametro del Corpo_celeste
    float forzaGravita;//!<forzaGravita Forza di gravità del Corpo_celeste

public:
    /*!
     * \brief Costruttore di default
     */
    Corpo_celeste();

    /*!
     * \brief Costruttore del Corpo_celeste
     */
    Corpo_celeste(QString, float,float);

    /*!
     * \brief Costruttore di copia
     */
    Corpo_celeste(Corpo_celeste&);

    /*!
     * \brief Distruttore di default
     */
    virtual ~Corpo_celeste();

    /*!
     * \brief Operatore di assegnazione di copia
     * \return oggetto di invocazione
     */
    Corpo_celeste& operator=(const Corpo_celeste&);

    /*!
     * \brief Confronta l'oggetto di invocazione con un Corpo_celeste e verifica se sono uguali
     * \return true se uguali, false altrimenti
     */
    virtual bool is_equal(const Corpo_celeste&)const;

    /*!
     * \brief Ritorna il nome del Corpo_celeste
     * \return nome
     */
    QString get_nome()const;

    /*!
     * \brief Ritorna il diametro del Corpo_celeste
     * \return diametro
     */
    float get_diametro()const;

    /*!
     * \brief Ritorna la forza di gravità del Corpo_celeste
     * \return forzaGravita
     */
    float get_forza_gravita()const;
    virtual float get_temperatura()const;
    virtual QString get_colore()const;
    virtual QString get_tipo()const;
    virtual const Pianeta* get_pianeta_orbitato()const;
    virtual Corpo_celeste* clone()= 0;
    virtual QString type_name()const = 0;
};

#endif // CORPO_CELESTE_H
