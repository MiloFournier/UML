#if ! defined (FOURNISSEUR_H)
#define FOURNISSEUR_H

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>
#include <fstream>
#include "Purificateur.h"
#include "Acteur.h"

class Fournisseur : public Acteur {

    public:
        //Constructeurs et destructeurs
        Fournisseur();
        Fournisseur(std::string id, std::list<Purificateur> listePurificateurs);
        ~Fournisseur();

        //Getters et Setters
        std::list<Purificateur> getListePurificateurs() const;
        void setListePurificateurs(std::list<Purificateur> listePurificateurs);

    protected:

        std::list<Purificateur> m_listePurificateurs;
};
#endif // FOURNISSEUR_H
