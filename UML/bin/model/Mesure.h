/*************************************************************************
						 Mesure  -  description
							-------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

/**
 * @file Mesure.h
 * entête de la classe Mesure
 * @author Gaspard
 * @date 2023
 * @version 1.0
 * @copyright Copyright 2023 Gaspard
 * @licence INSA
*/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if ! defined ( MESURE_H )
#define MESURE_H

#include <string>
using namespace std; 
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
/// @brief
/// Rôle de la classe <Mesure>
///
///
//------------------------------------------------------------------------

class Mesure {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	/**
	 * @brief Get the Date object
	 * @fn GetDate()
	 * 
	 * @return Date 
	 */
	string getDate() const;


	/**
	 * @brief Get the Valeur object
	 * @fn GetValeur()
	 * 
	 * @return double 
	 */
	double getValeur() const;


	/**
	 * @brief Get the Nom Gaz object
	 * @fn GetNomGaz()
	 * 
	 * @return string 
	 */
	string getNomGaz() const;


	/**
	 * @brief Set the Date object
	 * @fn SetDate(const Date&)
	 * 
	 * @param date 
	 */
	void setDate(const string& string);


	/**
	 * @brief Set the Valeur object
	 * @fn SetValeur(const double&)
	 * 
	 * @param valeur 
	 */
	void setValeur(const double& valeur);


	/**
	 * @brief Set the Nom Gaz object
	 * @fn SetNomGaz(const string&)
	 * 
	 * @param nomGaz 
	 */
	void setNomGaz(const string& nomGaz);

//------------------------------------------------- Surcharge d'opérateurs
	/// @fn Mesure& operator=(const Mesure& uneMesure)
	/// @brief
	/// Mode d'emploi :
	///
	/// Contrat :
	///
	Mesure& operator=(const Mesure& uneMesure);


	/**
	 * @brief surcharge de l'opérateur de test d'égalité
	 * test sur la valeur de la mesure
	 * @param uneMesure 
	 * @return true 
	 * @return false 
	 */
	bool operator==(const Mesure& uneMesure) const;


	/**
	 * @brief urcharge de l'opérateur de test d'infériorité stricte
	 * test sur la valeur de la mesure
	 * @param uneMesure 
	 * @return true 
	 * @return false 
	 */
	bool operator<(const Mesure& uneMesure) const;


//-------------------------------------------- Constructeurs - destructeur
	/** 
	 * @fn Mesure(const Mesure& uneMesure)
	 * @brief
	 * Mode d'emploi (constructeur de copie) :
	 * 
	 *  Contrat :
	 */
	Mesure(const Mesure& uneMesure);


	/** 
	 * @fn Mesure(const string&, const string&, const string&)
	 * @brief
	 * Mode d'emploi :
	 * 
	 *  Contrat :
	 */
	Mesure(const string& date, const string& valeur, const string& nomGaz);
	

	/** 
	 * @fn Mesure();
	 * @brief
	 * Mode d'emploi :
	 * 
	 *  Contrat :
	 */
	Mesure();
	

	/** 
	 * @fn Mesure(const Mesure& uneMesure)
	 * @brief
	 * Mode d'emploi :
	 * 
	 *  Contrat :
	 */
	virtual ~Mesure();


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string m_date;
	double m_valeur;
	string m_nomGaz;
};

//-------------------------------- Autres définitions dépendantes de <Mesure>

#endif /// MESURE_H

