#include "Capteur.h"

using namespace std;

//constructeur par défaut
Capteur::Capteur()
    : Appareil(), estFonctionnel(true) {
    //cout << "Appel au constructeur par défaut de Capteur" << endl;
}

//constructeur paramétré
Capteur::Capteur(Coordonnee c, string id, bool b)
    : Appareil(c, id), estFonctionnel(b) {
    //cout << "Appel au constructeur paramétré de Capteur" << endl;
}

//getters
bool Capteur::getEstFonctionnel() const {
    return estFonctionnel;
}
unordered_map<string, Mesure> Capteur::getLMesures_O3() const {
    return lmesures_O3;
}
unordered_map<string, Mesure> Capteur::getLMesures_NO2() const {
    return lmesures_NO2;
}
unordered_map<string, Mesure> Capteur::getLMesures_SO2() const {
    return lmesures_SO2;
}
unordered_map<string, Mesure> Capteur::getLMesures_PM10() const {
    return lmesures_PM10;
}

//setters
void Capteur::setEstFonctionnel(bool etat) {
    estFonctionnel = etat;
}
void Capteur::setLMesures_O3(string d, Mesure m) {
    lmesures_O3.insert({d, m});
}
void Capteur::setLMesures_NO2(string d, Mesure m) {
    lmesures_NO2.insert({d, m});
}
void Capteur::setLMesures_SO2(string d, Mesure m) {
    lmesures_SO2.insert({d, m});
}
void Capteur::setLMesures_PM10(string d, Mesure m) {
    lmesures_PM10.insert({d, m});
}

//surcharge de =
Capteur &Capteur::operator=(Capteur CapteurParam){
    //Appareil::operator=(CapteurParam); // est-ce qu'il me faut aussi une surcharge dans Appareil ?
    estFonctionnel = CapteurParam.getEstFonctionnel();
    lmesures_O3 = CapteurParam.getLMesures_O3();
    lmesures_NO2 = CapteurParam.getLMesures_NO2();
    lmesures_SO2 = CapteurParam.getLMesures_SO2();
    lmesures_PM10 = CapteurParam.getLMesures_PM10();
    return *this;
}

//destructeur
Capteur::~Capteur() {
    //cout << "Appel au destructeur de Capteur" << endl;
}