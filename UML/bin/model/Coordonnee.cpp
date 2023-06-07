#include <iostream>

#include "Coordonnee.h"

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

Coordonnee& Coordonnee::operator=(const Coordonnee& uneCoordonnee) {
	m_latitude = uneCoordonnee.getLatitude();
	m_longitude = uneCoordonnee.getLongitude();
	return *this;
}

Coordonnee::Coordonnee(const Coordonnee& uneCoordonnee) {
	m_latitude = uneCoordonnee.getLatitude();
	m_longitude = uneCoordonnee.getLongitude();
}

Coordonnee::Coordonnee(const double latitude, const double longitude) {
	m_latitude = latitude; 
	m_longitude = longitude;
}

Coordonnee::Coordonnee(const std::string& latitude, const std::string& longitude) {
	m_latitude = std::stod(latitude);
    m_longitude = std::stod(longitude);
}

Coordonnee::Coordonnee() {}

Coordonnee::~Coordonnee() {}