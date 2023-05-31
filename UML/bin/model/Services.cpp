//
// Created by Milo Fournier on 5/14/23.
//
    #include "Services.h"
    #include <cmath>

    using namespace std;

    Services::Services() {}

    Services::~Services() {}

   

    bool Services::verifierEtatCapteur(Capteur capteurParam) {
        double distanceDeVerification = 200.0; // en km
        double limiteDeMesure = 5.0; // valeur limite de différence entre les mesures
        int compteurErreurs = 0;
        int compteur = 0;

        Database *data = new Database();
        unordered_map<string, Capteur> listeDesCapteurs = data->getMCapteurs();
        // Parcours de tous les capteurs
        for (const auto& capteurTest : listeDesCapteurs) {
        // Vérification de la distance entre capteurParam et capteurTest
            if (capteurTest.second.calculDistance(capteurParam) < distanceDeVerification) {
                // Vérification de la date des mesures
                for(const auto &i : capteurParam.getLMesures_O3()) {
                    for(const auto &j : capteurTest.second.getLMesures_O3()) {
                        if(i.first == j.first) {
                            if(abs(i.second.getValeur() - j.second.getValeur()) > limiteDeMesure) {
                                compteurErreurs++;
                            }
                        }
                    }
                }
                for(const auto &i : capteurParam.getLMesures_NO2()) {
                    for(const auto &j : capteurTest.second.getLMesures_NO2()) {
                        if(i.first == j.first) {
                            if(abs(i.second.getValeur() - j.second.getValeur()) > limiteDeMesure) {
                                compteurErreurs++;
                            }
                        }
                    }
                }
                for(const auto &i : capteurParam.getLMesures_SO2()) {
                    for(const auto &j : capteurTest.second.getLMesures_SO2()) {
                        if(i.first == j.first) {
                            if(abs(i.second.getValeur() - j.second.getValeur()) > limiteDeMesure) {
                                compteurErreurs++;
                            }
                        }
                    }
                }
                for(const auto &i : capteurParam.getLMesures_PM10()) {
                    for(const auto &j : capteurTest.second.getLMesures_PM10()) {
                        if(i.first == j.first) {
                            if(abs(i.second.getValeur() - j.second.getValeur()) > limiteDeMesure) {
                                compteurErreurs++;
                            }
                        }
                    }
                }
                
                /*if (comparerDates(capteurParam.getMesures(), capteurTest.getMesures()) <= limiteDeTemps) {
                    // Parcours des gaz pour comparer les mesures
                    for (const auto& gaz : listeDesGaz) {
                        double difference = differenceValeurs(capteurParam.getMesure(gaz), capteurTest.getMesure(gaz));
                        if (difference > limiteDeMesure) {
                            compteurErreurs++;
                        }
                    }
                    compteur += 4; // Ajouter le nombre de mesures comparées (4 gaz)
                }*/
            }
            compteur += 4;
        }
        double tauxErreur = 0; 
        if (compteur){
            tauxErreur = (compteurErreurs / compteur) * 100.0;
        }
        bool dysfonctionnel = false;

        if (tauxErreur > 70.0) {
            dysfonctionnel = true;
        }

        return dysfonctionnel;
    }


    // code existant dans d'autres fichiers à insérer ici