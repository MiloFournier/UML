//
// Created by Milo Fournier on 5/11/23.
//

//à mettre dans Service.h
#include "Capteur.h"
#include "Date.h"
#include "Database.h"

bool Service::verifierEtatCapteur(Capteur capteurParam) {
    double distanceDeVerification = 200; //en km
    Date limiteDeTemps; //comment on fait pour dire c'est à 24h près ?
    int limiteDeMesure = 5;
    int compteurErreurs = 0;
    int compteur = 0;

    Database d = new Database(); // à remplacer par la database globale du main
    for(auto it = d.getMCapteurs().begin(); it != d.getMCapteurs().end(); ++it) {
        const string &clef = it->first; // clef du capteur actuel
        const Capteur &valeur = it->second; // valeur du capteur actuel

        if(valeur.calculDistance(capteurParam) < distanceDeVerification) { // si la distance est ok
            if() { //mettre la condition liée aux 24H
                unordered_map<Date, Mesure> mesuresO3 = valeur.getLMesures_O3();
                if() { // mettre le calcul de différence entre les mesures de cpateurParam et de valeur
                    compteurErreurs += 1;
                }
                unordered_map<Date, Mesure> mesuresNO2 = valeur.getLMesures_NO2();
                if() { // mettre le calcul de différence entre les mesures de cpateurParam et de valeur
                    compteurErreurs += 1;
                }
                unordered_map<Date, Mesure> mesuresSO2 = valeur.getLMesures_SO2();
                if() { // mettre le calcul de différence entre les mesures de cpateurParam et de valeur
                    compteurErreurs += 1;
                }
                unordered_map<Date, Mesure> mesuresPM10 = valeur.getLMesures_PM10();
                if() { // mettre le calcul de différence entre les mesures de cpateurParam et de valeur
                    compteurErreurs += 1;
                }
                compteur += 4;
            }
        }
    }
    double tauxErreur = (compteurErreurs/compteur) * 100;
    bool dysfonctionnel = false;

    if(tauxErreur > 70) {
        
        dysfonctionnel = true;
    }
    return dysfonctionnel;
}