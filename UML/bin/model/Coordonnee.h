/*************************************************************************
						 Coordonnee  -  description
							-------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

/**
 * @file Coordonnee.h
 * entête de la classe Coordonnee
 * @author Gaspard
 * @date 2023
 * @version 1.0
 * @copyright Copyright 2023 Gaspard
 * @licence INSA
*/

//---------- Interface de la classe <Coordonnee> (fichier Coordonnee.h) ----------------
#if ! defined ( COORDONNEE_H )
#define COORDONNEE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
/// @brief
/// Rôle de la classe <Coordonnee>
///
///
//------------------------------------------------------------------------

class Coordonnee {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	/**
	 * @brief Get the Latitude object
	 * @fn getLatitude() const
	 * 
	 * @return double 
	 */
	double getLatitude() const;


	/**
	 * @brief Get the Longitude object
	 * @fn getLongitude() const
	 * 
	 * @return double 
	 */
	double getLongitude() const;



	/**
	 * @brief Set the Latitude object
	 * @fn setLatitude(const double)
	 * 
	 * @param latitude 
	 */
	void setLatitude(const double latitude);


	/**
	 * @brief Set the Longitude object
	 * @fn setLongitude(const double)
	 * 
	 * @param longitude 
	 */
	void setLongitude(const double longitude);



//------------------------------------------------- Surcharge d'opérateurs
	/// @fn Coordonnee& operator=(const Coordonnee& unCoordonnee)
	/// @brief
	/// Mode d'emploi :
	///
	/// Contrat :
	///
	Coordonnee& operator=(const Coordonnee& uneCoordonnee);


//-------------------------------------------- Constructeurs - destructeur
	/** 
	 * @fn Coordonnee(const Coordonnee& uneCoordonnee)
	 * @brief
	 * Mode d'emploi (constructeur de copie) :
	 * 
	 *  Contrat :
	 */
	Coordonnee(const Coordonnee& uneCoordonnee);
	

	/**
	 * @fn Coordonnee(const double latitude, const double longitude)
	 * @brief Construct a new Coordonnee object
	 * 
	 * @param latitude 
	 * @param longitude 
	 */
	Coordonnee(const double latitude, const double longitude);

    Coordonnee(const std::string& latitude, const std::string& longitude);


	/** 
	 * @fn Coordonnee();
	 * @brief
	 * Mode d'emploi :
	 * 
	 *  Contrat :
	 */
	Coordonnee();
	

	/** 
	 * @fn Coordonnee(const Coordonnee& uneCoordonnee)
	 * @brief
	 * Mode d'emploi :
	 * 
	 *  Contrat :
	 */
	virtual ~Coordonnee();


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	double m_latitude;
	double m_longitude;
};

//-------------------------------- Autres définitions dépendantes de <Coordonnee>

#endif /// COORDONNEE_H

