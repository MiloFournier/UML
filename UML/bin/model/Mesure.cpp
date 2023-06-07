#include <iostream>
#include <stdlib.h>
#include "Mesure.h"

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

Mesure& Mesure::operator=(const Mesure& uneMesure) {
	m_date = uneMesure.getDate();
	m_valeur = uneMesure.getValeur();
	m_nomGaz = uneMesure.getNomGaz();
	return *this;
}

bool Mesure::operator==(const Mesure& uneMesure) const {
	return (m_valeur == uneMesure.getValeur());
}

bool Mesure::operator<(const Mesure& uneMesure) const {
	return (m_valeur < uneMesure.getValeur());
}

Mesure::Mesure(const Mesure& uneMesure) {
	m_date = uneMesure.getDate();
	m_valeur = uneMesure.getValeur();
	m_nomGaz = uneMesure.getNomGaz();
}

Mesure::Mesure(const string& date, const string& valeur, const string& nomGaz) {
	m_date = date;
	m_valeur = atof(valeur.c_str());
	m_nomGaz = nomGaz;
}

Mesure::Mesure() {}

Mesure::~Mesure() {}