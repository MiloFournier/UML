#include <iostream>
#include "AttributMesure.h"

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

AttributMesure& AttributMesure::operator=(const AttributMesure& unAttributMesure) {
    m_nomGaz = unAttributMesure.m_nomGaz;
    m_unite = unAttributMesure.m_unite;
    m_description = unAttributMesure.m_description;
    return *this;
}

AttributMesure::AttributMesure(const AttributMesure& unAttributMesure) {}

AttributMesure::AttributMesure() {}

AttributMesure::~AttributMesure() {}