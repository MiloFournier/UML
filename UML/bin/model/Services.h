#ifndef GL_ET_UML_SERVICES_H
#define GL_ET_UML_SERVICES_H

#include "Capteur.h"
#include "Database.h"
#include "Purificateur.h"
#include <stdbool.h>

using namespace std;

class Services {
    public:
        //constructeur & destructeur
        Services();
        virtual ~Services();

        //services
        bool verifierEtatCapteur(Capteur &capteurParam, Database &data, bool affichage);

        double * obtenirQualiteAirPosition(Database &d, Coordonnee coordonneeParam, string dateParam);
};

#endif //GL_ET_UML_SERVICES_H