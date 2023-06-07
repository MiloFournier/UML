#include "Appareil.h"
#include <iostream>
#include <cmath>

using namespace std;

//constructeur par défaut
Appareil::Appareil()
    : m_position(0, 0), m_id("") {
};

//constructeur paramétré
Appareil::Appareil(Coordonnee c, string s)
    : m_position(c), m_id(s) {
}

//getters
Coordonnee Appareil::getPosition() const {
    return m_position;
}
string Appareil::getId() const {
    return m_id;
}

//setters
void Appareil::setPosition(const Coordonnee c) {
    m_position = c;
}
void Appareil::setId(const string s) {
    m_id = s;
}

//services
double Appareil::calculDistance(Appareil &a) const {
    double latThis = (M_PI * this->getPosition().getLatitude()) / 180;
    double lngThis = (M_PI * this->getPosition().getLongitude()) / 180;
    double lat = (M_PI * a.getPosition().getLatitude()) / 180;
    double lng = (M_PI * a.getPosition().getLongitude()) / 180;

    return 6371 * acos(sin(latThis)*sin(lat) + cos(latThis)*cos(lat)*cos(lngThis - lng));
}

double Appareil::calculDistance(Coordonnee pos) const{
    double latThis = (M_PI * this->getPosition().getLatitude()) / 180;
    double lngThis = (M_PI * this->getPosition().getLongitude()) / 180;
    double lat = (M_PI * pos.getLatitude()) / 180;
    double lng = (M_PI * pos.getLongitude()) / 180;

    return 6371 * acos(sin(latThis)*sin(lat) + cos(latThis)*cos(lat)*cos(lngThis - lng));
}

//destructeur
Appareil::~Appareil() {}