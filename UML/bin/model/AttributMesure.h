/*************************************************************************
						 AttributMesure  -  description
							-------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

/**
 * @file AttributMesure.h
 * entête de la classe AttributMesure
 * @author Gaspard
 * @date 2023
 * @version 1.0
 * @copyright Copyright 2023 Gaspard
 * @licence INSA
*/

//---------- Interface de la classe <AttributMesure> (fichier AttributMesure.h) ----------------
#if ! defined ( ATTRIBUTMESURE_H )
#define ATTRIBUTMESURE_H
#include <string>
#include <iostream>
using namespace std; 

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
/// @brief
/// Rôle de la classe <AttributMesure>
///
///
//------------------------------------------------------------------------

class AttributMesure {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	/**
	 * @brief Get the Nom Gaz object
	 * 
	 * @return string 
	 */
	string getNomGaz() const;


	/**
	 * @brief Get the Unite object
	 * 
	 * @return string 
	 */
	string getUnite() const;


	/**
	 * @brief Get the Description object
	 * 
	 * @return string 
	 */
	string getDescription() const;


	/**
	 * @brief Set the Nom Gaz object
	 * 
	 * @param nomGaz 
	 */
	void setNomGaz(const string nomGaz);


	/**
	 * @brief Set the Unite object
	 * 
	 * @param unite 
	 */
	void setUnite(const string unite);


	/**
	 * @brief Set the Description object
	 * 
	 * @param description 
	 */
	void setDescription(const string description);

//------------------------------------------------- Surcharge d'opérateurs
	/// @fn AttributMesure& operator=(const AttributMesure& unAttributMesure)
	/// @brief
	/// Mode d'emploi :
	///
	/// Contrat :
	///
	AttributMesure& operator=(const AttributMesure& unAttributMesure);


//-------------------------------------------- Constructeurs - destructeur
	/** 
	 * @fn AttributMesure(const AttributMesure& unAttributMesure)
	 * @brief
	 * Mode d'emploi (constructeur de copie) :
	 * 
	 *  Contrat :
	 */
	AttributMesure(const AttributMesure& unAttributMesure);
	

	/** 
	 * @fn AttributMesure();
	 * @brief
	 * Mode d'emploi :
	 * 
	 *  Contrat :
	 */
	AttributMesure();
	

	/** 
	 * @fn AttributMesure(const AttributMesure& unAttributMesure)
	 * @brief
	 * Mode d'emploi :
	 * 
	 *  Contrat :
	 */
	virtual ~AttributMesure();


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string m_nomGaz;
	string m_unite;
	string m_description;
};

//-------------------------------- Autres définitions dépendantes de <AttributMesure>

#endif /// ATTRIBUTMESURE_H

