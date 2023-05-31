#include "Fournisseur.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>
#include <fstream>
using namespace std; 

Fournisseur::Fournisseur(std::string id, std::list<Purificateur> listePurificateurs)
    : Acteur(id), m_listePurificateurs(listePurificateurs) {}

Fournisseur::~Fournisseur() {}

std::list<Purificateur> Fournisseur::getListePurificateurs() const {
    return m_listePurificateurs;
}

void Fournisseur::setListePurificateurs(std::list<Purificateur> listePurificateurs) {
    m_listePurificateurs = listePurificateurs;
}

