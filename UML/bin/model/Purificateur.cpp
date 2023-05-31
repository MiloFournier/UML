//
// Created by Milo Fournier on 5/10/23.
//

#include "Purificateur.h"
#include <iostream>

using namespace std;

//constructeur par défaut
Purificateur::Purificateur()
    : Appareil(), m_demarrage(""), m_arret("") { //test avec Kous pour Appareil() ou pas
    cout << "Appel au constructeur par défaut de Purificateur" << endl;
}

//constructeur paramétré
Purificateur::Purificateur(Coordonnee c, string s, string demarrage, string arret)
    : Appareil(c, s), m_demarrage(demarrage), m_arret(arret) {
    cout << "Appel au constructeur paramétré de Purificateur" << endl;
}

//getters
string Purificateur::getDemarrage() const{
    return m_demarrage;
}
string Purificateur::getArret() const {
    return m_arret;
}
string Purificateur::getId() const {
    return Appareil::getId();
}
Coordonnee Purificateur::getCoordonnee() const {
    return Appareil::getPosition();
}

//setters
void Purificateur::setDemarrage(const string d) {
    m_demarrage = d;
}
void Purificateur::setArret(const string d) {
    m_arret = d;
}
void Purificateur::setId(const string s){
    Appareil::setId(s);
}
void Purificateur::setCoordonnee(const Coordonnee s){
    Appareil::setPosition(s);
}

//surcharge de =
Purificateur &Purificateur::operator=(Purificateur PurificateurParam){
    //Appareil::operator=(PurificateurParam);
    m_demarrage = PurificateurParam.getDemarrage();
    m_arret = PurificateurParam.getArret();
    return *this;
}

//destructeur
Purificateur::~Purificateur() {
    cout << "Appel au destructeur de Purificateur" << endl;
}