#ifndef GL_ET_UML_APPAREIL_H
#define GL_ET_UML_APPAREIL_H

#include <string>
#include "Coordonnee.h"
#include <cmath>

using namespace std;

class Appareil {

    public:
        //constructeurs & destructeur
        Appareil();
        Appareil(Coordonnee c, string s);
        virtual ~Appareil() = 0; //méthode virtuelle pure

        //getters
        Coordonnee getPosition() const;
        string getId() const;

        //setters
        void setPosition(const Coordonnee c);
        void setId(const string s);

        //services
        double calculDistance(Appareil &a) const;
        double calculDistance(Coordonnee pos) const;

    protected:
        Coordonnee m_position;
        string m_id;
};


#endif //GL_ET_UML_APPAREIL_H