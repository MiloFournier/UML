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
        bool verifierEtatCapteur(Capteur &capteurParam, Database &data);
        //double quantifierImpactPurificateur(Purificateur purificateurParam);
};

#endif //GL_ET_UML_SERVICES_H