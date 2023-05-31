/*************************************************************************
						 Coordonnee  -  description
							-------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

#ifdef MAP
#include <iostream>
#define construction(p) (std::cout << "Appel au constructeur de <Coordonnee>"\
<< " avec this = " << p << std::endl)
#define constructionCopie(p) (std::cout << "Appel au constructeur"\
<< " par copie de <Coordonnee> avec this = " << p << std::endl)
#define destruction(p) (std::cout << "Appel au destructeur de <Coordonnee>"\
<< " avec this = " << p << std::endl)
#else
#define construction(p) ((void)0)
#define constructionCopie(p) ((void)0)
#define destruction(p) ((void)0)
#endif

#ifdef TRACE
#include <iostream>
#define debug(expression) (std::cout << __FILE__ << ":" << __LINE__ << \
" -> " << (expression) << std::endl)
#else
#define debug(expression) ((void)0)
#endif


//---------- Réalisation de la classe <Coordonnee> (fichier Coordonnee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Coordonnee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
double Coordonnee::getLatitude() const {
	return m_latitude;
}


double Coordonnee::getLongitude() const {
	return m_longitude;
}


void Coordonnee::setLatitude(const double latitude) {
	m_latitude = latitude;
}


void Coordonnee::setLongitude(const double longitude) {
	m_longitude = longitude;
}


//------------------------------------------------- Surcharge d'opérateurs
Coordonnee& Coordonnee::operator=(const Coordonnee& uneCoordonnee) {
	m_latitude = uneCoordonnee.getLatitude();
	m_longitude = uneCoordonnee.getLongitude();
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Coordonnee::Coordonnee(const Coordonnee& uneCoordonnee) {
	m_latitude = uneCoordonnee.getLatitude();
	m_longitude = uneCoordonnee.getLongitude();
	constructionCopie(this);
} //----- Fin de Coordonnee (constructeur de copie)


Coordonnee::Coordonnee(const double latitude, const double longitude) {
	m_latitude = latitude; 
	m_longitude = longitude; 
	construction(this);
} //----- Fin de Coordonnee

Coordonnee::Coordonnee(const std::string& latitude, const std::string& longitude) {
    //std::cout << "je suis dans le constructeur de coodronnées" << std::endl; 
	m_latitude = std::stod(latitude);
    m_longitude = std::stod(longitude);
    construction(this);
}

Coordonnee::Coordonnee() {
	construction(this);
} //----- Fin de Coordonnee


Coordonnee::~Coordonnee() {
	destruction(this);
} //----- Fin de ~Coordonnee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

