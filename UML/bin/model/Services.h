//
// Created by Milo Fournier on 5/14/23.
//

#ifndef GL_ET_UML_SERVICES_H
#define GL_ET_UML_SERVICES_H

#include "Capteur.h"
#include "Database.h"
#include "Purificateur.h"

using namespace std;

class Services {
    public:
        //constructeur & destructeur
        Services();
        virtual ~Services();

        //services
        bool verifierEtatCapteur(Capteur capteurParam);
        double[] obtenirQualiteAirPosition(Coordonnee coordonneeParam, Date dateParam);
        double quantifierImpactPurificateur(Purificateur purificateurParam);
};

#endif //GL_ET_UML_SERVICES_H