#include "Particulier.h"

using namespace std;

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>
#include <fstream>

// Constructeur par défaut
Particulier::Particulier() : m_nbPoints(0), m_honnete(false), m_listeCapteurs() {}

// Constructeur avec paramètres
Particulier::Particulier(string id, int nbPoints, bool honnete) : Acteur(id), m_nbPoints(nbPoints), m_honnete(honnete), m_listeCapteurs() {}

// Destructeur

Particulier::~Particulier() {}

// Accesseurs
int Particulier::getNbPoints() const { return m_nbPoints; }
void Particulier::setNbPoints(int nbPoints) { this->m_nbPoints = nbPoints; }

bool Particulier::estHonnete() const { return m_honnete; }
void Particulier::setHonnete(bool honnete) { this->m_honnete = honnete; }

list<Capteur> Particulier::getListeCapteurs() const { return m_listeCapteurs; }
void Particulier::setListeCapteurs(list<Capteur> listeCapteurs) { this->m_listeCapteurs = listeCapteurs; }