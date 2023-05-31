//
// Created by Milo Fournier on 5/14/23.
//

#include "Capteur.h"
#include "Date.h"
#include "Database.h"
#include "Purificateur.h"

double Service::quantifierImpactPurificateur(Purificateur purificateurParam) {
    bool condition = true;
    double rayonAction = 0.0;
    double max = 0.0;

    while(condition == true) {
        double min = 1000000;
        Capteur capteurProche = null;

        //pour chaque capteur
        Database d = new Database(); // à remplacer par la database globale du main
        for(auto it = d.getMCapteurs().begin(); it != d.getMCapteurs().end(); ++it) {
            const string &clef = it->first; // clef du capteur actuel
            const Capteur &valeur = it->second; // valeur du capteur actuel

            double distance = valeur.calculDistance(purificateurParam);
            if(distance < min && distance > max) {
                min = distance;
                capteurProche = valeur; // attention il faut une surcharge ici
                max = distance;
            }
        }

        double tableauAvant[] = {0.0, 0.0, 0.0, 0.0};
        double tableauApres[] = {0.0, 0.0, 0.0, 0.0};
        double tableauMoyenneAvant[] = {0.0, 0.0, 0.0, 0.0};
        double tableauMoyenneApres[] = {0.0, 0.0, 0.0, 0.0};

        // revoir comment on accède aux gaz de capteurProche
    }
}