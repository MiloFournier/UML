#if ! defined ( ACTEUR_H)
#define ACTEUR_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <fstream>
#include <string>

using namespace std;

class Acteur {

    protected:
        string m_id;

    public:

        // Constructeurs et destructeur
        Acteur();
        Acteur(string id);
        virtual ~Acteur() = 0;

        // Accesseurs
        std::string getId() const;
        void setId(string id);
};

#endif