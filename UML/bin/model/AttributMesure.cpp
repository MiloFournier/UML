/*************************************************************************
						 AttributMesure  -  description
							-------------------
	début                : $DATE$
	copyright            : (C) $YEAR$ par $AUTHOR$
	e-mail               : $EMAIL$
*************************************************************************/

#ifdef MAP
#include <iostream>
#define construction(p) (std::cout << "Appel au constructeur de <AttributMesure>"\
<< " avec this = " << p << std::endl)
#define constructionCopie(p) (std::cout << "Appel au constructeur"\
<< " par copie de <AttributMesure> avec this = " << p << std::endl)
#define destruction(p) (std::cout << "Appel au destructeur de <AttributMesure>"\
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


//---------- Réalisation de la classe <AttributMesure> (fichier AttributMesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AttributMesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string AttributMesure::getNomGaz() const {
	return m_nomGaz;
}


string AttributMesure::getUnite() const {
	return m_unite;
}


string AttributMesure::getDescription() const {
	return m_description;
}


void AttributMesure::setNomGaz(const string nomGaz) {
	m_nomGaz = nomGaz;
}


void AttributMesure::setUnite(const string unite) {
	m_unite = unite;
}


void AttributMesure::setDescription(const string description) {
	m_description = description;
}


//------------------------------------------------- Surcharge d'opérateurs
AttributMesure& AttributMesure::operator=(const AttributMesure& unAttributMesure) {
    m_nomGaz = unAttributMesure.m_nomGaz;
    m_unite = unAttributMesure.m_unite;
    m_description = unAttributMesure.m_description;
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AttributMesure::AttributMesure(const AttributMesure& unAttributMesure) {
	constructionCopie(this);
} //----- Fin de AttributMesure (constructeur de copie)


AttributMesure::AttributMesure() {
	construction(this);
} //----- Fin de AttributMesure


AttributMesure::~AttributMesure() {
	destruction(this);
} //----- Fin de ~AttributMesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

