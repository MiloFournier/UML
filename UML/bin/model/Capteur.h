//
// Created by Milo Fournier on 5/10/23.
//

#ifndef GL_ET_UML_CAPTEUR_H
#define GL_ET_UML_CAPTEUR_H

#include <unordered_map>
#include "Mesure.h"
#include "Coordonnee.h"
#include "Appareil.h"
#include <iostream>

using namespace std;

class Capteur : public Appareil{
    public:
        //constructeurs & destructeur
        Capteur();
        Capteur(Coordonnee c, string id, bool b);
        ~Capteur();

        //getters
        bool getEstFonctionnel() const;
        unordered_map<string, Mesure> getLMesures_O3() const;
        unordered_map<string, Mesure> getLMesures_NO2() const;
        unordered_map<string, Mesure> getLMesures_SO2() const;
        unordered_map<string, Mesure> getLMesures_PM10() const;

        //setters
        void setEstFonctionnel(bool etat);
        void setLMesures_O3(string d, Mesure m);
        void setLMesures_NO2(string d, Mesure m);
        void setLMesures_SO2(string d, Mesure m);
        void setLMesures_PM10(string d, Mesure m);

        //surcharge de =
        Capteur &operator=(Capteur CapteurParam);

        //services
        //double calculDistance(Appareil a);
        //double calculDistance(Coordonnee pos);

    protected:
        bool estFonctionnel;
        unordered_map<string, Mesure> lmesures_O3;
        unordered_map<string, Mesure> lmesures_NO2;
        unordered_map<string, Mesure> lmesures_SO2;
        unordered_map<string, Mesure> lmesures_PM10;
};


#endif //GL_ET_UML_CAPTEUR_H