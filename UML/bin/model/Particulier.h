#if ! defined ( PARTICULIER_H)
#define PARTICULIER_H

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>
#include <fstream>

#include "Acteur.h"
#include "Capteur.h"

class Particulier : public Acteur {

    private:
        int m_nbPoints;
        bool m_honnete;
        std::list<Capteur> m_listeCapteurs;

    public:
        // Constructeurs et destructeur
        Particulier();
        Particulier(std::string id, int nbPoints, bool honnete);
        virtual ~Particulier();

        // Getters
        int getNbPoints() const;
        void setNbPoints(int nbPoints);

        bool estHonnete() const;
        void setHonnete(bool honnete);

        std::list<Capteur> getListeCapteurs() const;
        void setListeCapteurs(std::list<Capteur> listeCapteurs);
};
#endif