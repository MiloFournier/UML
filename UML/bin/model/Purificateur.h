#ifndef GL_ET_UML_PURIFICATEUR_H
#define GL_ET_UML_PURIFICATEUR_H

#include "Appareil.h"
#include "Coordonnee.h"

using namespace std;

class Purificateur : public Appareil{

    public:
        //constructeurs et destructeur
        Purificateur();
        Purificateur(Coordonnee c, string s, string demarrage, string arret);
        virtual ~Purificateur();

        //surcharge de =
        Purificateur &operator=(const Purificateur PurificateurParam);

        //getters
        string getDemarrage() const;
        string getArret() const;
        string getId() const;
        Coordonnee getCoordonnee() const;

        //setters
        void setDemarrage(const string d);
        void setArret(const string d);
        void setId(const string s);
        void setCoordonnee(const Coordonnee c);

    protected:
        string m_demarrage;
        string m_arret;
};

#endif