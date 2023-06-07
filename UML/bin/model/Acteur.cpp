#include "Acteur.h"

// Constructeur par défaut
Acteur::Acteur() : m_id("") {}

// Constructeur avec paramètres
Acteur::Acteur(string id) : m_id(id) {}

// Destructeur virtuel
Acteur::~Acteur() {}

// Accesseurs
string Acteur::getId() const { return m_id; }
void Acteur::setId(string id) { this->m_id = id; }