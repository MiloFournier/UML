/*************************************************************************
						 Mesure  -  description
							-------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

#ifdef MAP
#include <iostream>
#define construction(p) (std::cout << "Appel au constructeur de <Mesure>"\
<< " avec this = " << p << std::endl)
#define constructionCopie(p) (std::cout << "Appel au constructeur"\
<< " par copie de <Mesure> avec this = " << p << std::endl)
#define destruction(p) (std::cout << "Appel au destructeur de <Mesure>"\
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


//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <stdlib.h>
//------------------------------------------------------ Include personnel
#include "Mesure.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Mesure::getDate() const{
	return m_date;
}


double Mesure::getValeur() const{
	return m_valeur;
}


string Mesure::getNomGaz() const{
	return m_nomGaz;
}


void Mesure::setDate(const string& date){
	m_date = date;
}


void Mesure::setValeur(const double& valeur){
	m_valeur = valeur;
}


void Mesure::setNomGaz(const string & nomGaz){
	m_nomGaz = nomGaz;
}


//------------------------------------------------- Surcharge d'opérateurs
Mesure& Mesure::operator=(const Mesure& uneMesure) {
	m_date = uneMesure.getDate();
	m_valeur = uneMesure.getValeur();
	m_nomGaz = uneMesure.getNomGaz();
	return *this;
} //----- Fin de operator =


bool Mesure::operator==(const Mesure& uneMesure) const {
	return (m_valeur == uneMesure.getValeur());
}


bool Mesure::operator<(const Mesure& uneMesure) const {
	return (m_valeur < uneMesure.getValeur());
}


//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure(const Mesure& uneMesure) {
	m_date = uneMesure.getDate();
	m_valeur = uneMesure.getValeur();
	m_nomGaz = uneMesure.getNomGaz();
	constructionCopie(this);
} //----- Fin de Mesure (constructeur de copie)


Mesure::Mesure(const string& date, const string& valeur, const string& nomGaz) {
	m_date = date;
	m_valeur = atof(valeur.c_str());
	m_nomGaz = nomGaz;
}


Mesure::Mesure() {
	construction(this);
} //----- Fin de Mesure


Mesure::~Mesure() {
	destruction(this);
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

