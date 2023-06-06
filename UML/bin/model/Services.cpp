    #include "Services.h"
    #include <cmath>

    using namespace std;

    Services::Services() {}

    Services::~Services() {}

    bool Services::verifierEtatCapteur(Capteur &capteurParam, Database &data, bool affichage) {
        double distanceDeVerification = 200.0; // en km
        double limiteDeMesure = 20.0; // valeur limite de différence entre les mesures
        int compteurErreurs = 0;
        int compteur = 0;
        unordered_map<string, Capteur> listeDesCapteurs = data.getMCapteurs();
        const auto& it = listeDesCapteurs.begin();
        if(listeDesCapteurs.size() != 0)
            if(affichage)
                cout << "   distance aux autres capteurs: " << endl;
        for (const auto& capteurTest : listeDesCapteurs) {
            if(affichage)
                cout << "           " << capteurTest.second.getId() << ": " << capteurTest.second.calculDistance(capteurParam); //<< endl;
            if (capteurTest.second.calculDistance(capteurParam) < distanceDeVerification && capteurTest.second.calculDistance(capteurParam) != 0.0) {
                if(affichage)
                    cout << " (distance: ok)";
                for(const auto &i : capteurParam.getLMesures_O3()) {
                    for(const auto &j : capteurTest.second.getLMesures_O3()) {
                        string str;
                        str = j.first;
                        str.erase(0, 1);
                        if(str.erase(0, 1) == i.first) {
                            if(abs(i.second.getValeur() - j.second.getValeur()) >= limiteDeMesure) {
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
                compteur += 4;
            }
            if(affichage)
                cout << endl;
        }
        double tauxErreur = 0;
        if (compteur>0){
            // Le cast est obligatoire sinon le résultat de la division est 0
            tauxErreur = (static_cast<double>(compteurErreurs) / compteur) * 100.0;
        }
        bool dysfonctionnel = false;
        if (tauxErreur > 70.0) {
            dysfonctionnel = true;
        }
        if (dysfonctionnel){
            capteurParam.setEstFonctionnel(false); 
        } else {
            capteurParam.setEstFonctionnel(true); 
        }
        return dysfonctionnel;
    }

double * Services::obtenirQualiteAirPosition(Database &d, Coordonnee coordonneeParam, string dateParam) {
    double rayonDeVerification = 200; // en km
    double* tableau = new double[4];
    tableau[0] = 0.0;
    tableau[1] = 0.0;
    tableau[2] = 0.0;
    tableau[3] = 0.0;
    int compteur = 0;


    for(const auto& it : d.getMCapteurs()) {
        //string clef = it.first; // clef du capteur actuel
        Capteur valeur = it.second; // valeur du capteur actuel
        if(valeur.calculDistance(coordonneeParam) < rayonDeVerification) {
            if(verifierEtatCapteur(valeur, d, 0) == false) {
                compteur ++;
                for(const auto& itO3 : valeur.getLMesures_O3()){
                    
                    if(itO3.first == dateParam){
                        tableau[0] += itO3.second.getValeur();
                    }
                }

                for(const auto &i : valeur.getLMesures_NO2()) {
                    if(i.first == dateParam) {
                        tableau[2] += i.second.getValeur();
                    }
                }
                
                for(const auto &i : valeur.getLMesures_SO2()) {
                    if(i.first == dateParam) {
                        tableau[1] += i.second.getValeur();
                    }
                }

                for(const auto &i : valeur.getLMesures_PM10()) {
                    if(i.first == dateParam) {
                        tableau[3] += i.second.getValeur();
                    }
                }

            }
        }
    }

    if(compteur != 0){
        for(int i = 0; i < 4; ++i) {
            tableau[i] = tableau[i] / compteur;
        }
    }
    
    return tableau;
}