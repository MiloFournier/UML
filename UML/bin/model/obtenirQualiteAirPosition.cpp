#include "Capteur.h"
#include "Database.h"

double[] Service::obtenirQualiteAirPosition(Coordonnee coordonneeParam, string dateParam) {
    double rayonDeVerification = 200; // en km
    double tableau[] = {0.0, 0.0, 0.0, 0.0};
    int compteur = 0;

    Database d = new Database(); // à remplacer par la database globale du main
    for(auto it = d.getMCapteurs().begin(); it != d.getMCapteurs().end(); ++it) {
        const string &clef = it->first; // clef du capteur actuel
        const Capteur &valeur = it->second; // valeur du capteur actuel

        if(valeur.calculDistance(coordonneeParam) < rayonDeVerification) {
            if(verifierEtatCapteur(valeur) == true) {
                auto itFindO3 = valeur.getLMesures_O3.find(dateParam);
                auto itFindNO2 = valeur.getLMesures_NO2.find(dateParam);
                auto itFindSO2 = valeur.getLMesures_SO2.find(dateParam);
                auto itFindPM10 = valeur.getLMesures_PM10.find(dateParam);
                if(itFindO3->second != null && itFindNO2->second != null &&
                   itFindSO2->second != null && itFindPM10->second != null) {

                    tableau[0] += itFindO3->second;
                    tableau[1] += itFindSO2->second;
                    tableau[2] += itFindNO2->second;
                    tableau[3] += itFindPM10->second;
                }
                compteur += 1;
            }
        }
    }

    for(int i = 0; i < 4; ++i) {
        tableau[i] = tableau[i] / compteur;
    }

    return tableau;
}