//
// Created by Milo Fournier on 5/14/23.
//
    #include "Services.h"
    #include <stdbool.h>

    using namespace std;

    bool Service::verifierEtatCapteur(Capteur capteurParam) {

        double distanceDeVerification = 200.0; // en km
        int limiteDeTemps = 1; // même jour
        double limiteDeMesure = 0.0; // valeur limite de différence entre les mesures
        int compteurErreurs = 0;
        int compteur = 0;

        // Parcours de tous les capteurs
        for (const auto& capteurTest : listeDesCapteurs) {
        // Vérification de la distance entre capteurParam et capteurTest
            if (calculDistance(capteurParam, capteurTest) < distanceDeVerification) {
                // Vérification de la date des mesures
                if (comparerDates(capteurParam.getMesures(), capteurTest.getMesures()) <= limiteDeTemps) {
                    // Parcours des gaz pour comparer les mesures
                    for (const auto& gaz : listeDesGaz) {
                        double difference = differenceValeurs(capteurParam.getMesure(gaz), capteurTest.getMesure(gaz));
                        if (difference > limiteDeMesure) {
                            compteurErreurs++;
                        }
                    }
                    compteur += 4; // Ajouter le nombre de mesures comparées (4 gaz)
                }
            }
        }

        double tauxErreur = (compteurErreurs / compteur) * 100.0;
        bool dysfonctionnel = false;

        if (tauxErreur > 70.0) {
            dysfonctionnel = true;
        }

        return !dysfonctionnel;
    }


    // code existant dans d'autres fichiers à insérer ici