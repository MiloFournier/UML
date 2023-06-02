    #include "Services.h"
    #include <cmath>

    using namespace std;

    Services::Services() {}

    Services::~Services() {}

    bool Services::verifierEtatCapteur(Capteur &capteurParam, Database &data, bool affichage) {
        double distanceDeVerification = 200.0; // en km
        double limiteDeMesure = 5.0; // valeur limite de différence entre les mesures
        int compteurErreurs = 0;
        int compteur = 0;
        if(affichage)
            cout << "\n   \n   entrée dans la méthode verifierEtatCapteur: ok" << endl;
        //Database *data = new Database();
        //data->InitCapteurs();
        unordered_map<string, Capteur> listeDesCapteurs = data.getMCapteurs();
        // Parcours de tous les capteurs
        //cout << data->getMCapteurs().size() << endl;
        const auto& it = listeDesCapteurs.begin();
        //cout << "size de listeDesCapteurs: " << listeDesCapteurs.size() << endl;
        if(listeDesCapteurs.size() != 0)
            if(affichage)
                cout << "   distance aux autres capteurs: " << endl;
        for (const auto& capteurTest : listeDesCapteurs) {
        // Vérification de la distance entre capteurParam et capteurTest
            if(affichage)
                cout << "           " << capteurTest.second.getId() << ": " << capteurTest.second.calculDistance(capteurParam); //<< endl;
            if (capteurTest.second.calculDistance(capteurParam) < distanceDeVerification && capteurTest.second.calculDistance(capteurParam) != 0.0) {
                if(affichage)
                    cout << " (distance: ok)";
                // Vérification de la date des mesures
                for(const auto &i : capteurParam.getLMesures_O3()) {
                    for(const auto &j : capteurTest.second.getLMesures_O3()) {
                        //cout << "i.first: " << i.first << endl;
                        //cout << "j.first: " << j.first << endl;
                        //i.first.erase(0, 1);
                        string str;
                        str = j.first;
                        str.erase(0, 1);
                        //cout << str << endl;
                        if(str.erase(0, 1) == i.first) {
                            //cout << "    vérification de la date: ok" << endl;
                            //cout << "    i.second.getValeur(): " << i.second.getValeur() << endl;
                            //cout << "    j.second.getValeur(): " << j.second.getValeur() << endl;
                            //cout << "    abs(i.second.getValeur() - j.second.getValeur()): " << abs(i.second.getValeur() - j.second.getValeur()) << endl;
                            //cout << "    limiteDeMesure " << limiteDeMesure << endl;
                            if(abs(i.second.getValeur() - j.second.getValeur()) >= limiteDeMesure) {
                                //cout << "   vérification de la limite de valeur: ok" << endl;
                                compteurErreurs++;
                                //cout << "    compteurErreurs " << compteurErreurs << endl;
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
            cout << endl;
        }
        double tauxErreur = 0;
        if(affichage) {
            cout << "\n   compteurErreurs: " << compteurErreurs << endl;
            cout << "   compteur: " << compteur << endl;
        }
        if (compteur>0){
            // Le cast est obligatoire sinon le résultat de la division est 0
            tauxErreur = (static_cast<double>(compteurErreurs) / compteur) * 100.0;
        }
        if(affichage)
            cout << "   tauxErreur: " << tauxErreur << endl;
        bool dysfonctionnel = false;
        if (tauxErreur > 70.0) {
            dysfonctionnel = true;
        }
        if (dysfonctionnel){
            capteurParam.setEstFonctionnel(false); 
        } else {
            capteurParam.setEstFonctionnel(true); 
        }
        if(affichage)
            cout << "   dysfonctionnel: " << dysfonctionnel << "\n\n" <<endl;
        return dysfonctionnel;
    }

    double * Services::obtenirQualiteAirPosition(Database* d, Coordonnee coordonneeParam, string dateParam) {
        double rayonDeVerification = 200; // en km
        double tableau[4];
        tableau[0] = 0.0;
        tableau[1] = 0.0;
        tableau[2] = 0.0;
        tableau[3] = 0.0;
        int compteur = 0;

        unordered_map<string, Capteur> listeDesCapteurs = d->getMCapteurs();
        for(const auto& it : listeDesCapteurs) {
            string clef = it.first; // clef du capteur actuel
            Capteur valeur = it.second; // valeur du capteur actuel
            //cout << "Coucou la clé" << clef << endl;

            if(valeur.calculDistance(coordonneeParam) < rayonDeVerification) {
                if(verifierEtatCapteur(valeur, *d, false) == true) {
                    cout<<"error"<<endl; // NE S'AFFICHE PAS, NORMAL ??
                    unordered_map<string, Mesure>::iterator itFindO3 = valeur.getLMesures_O3().find(dateParam);
                    unordered_map<string, Mesure>::iterator itFindNO2 = valeur.getLMesures_NO2().find(dateParam);
                    unordered_map<string, Mesure>::iterator itFindSO2 = valeur.getLMesures_SO2().find(dateParam);
                    unordered_map<string, Mesure>::iterator itFindPM10 = valeur.getLMesures_PM10().find(dateParam);

                    if(itFindO3 != valeur.getLMesures_O3().end()) {
                        compteur += 1;
                        tableau[0] += itFindO3->second.getValeur();
                        cout << "Mesures " << itFindO3->second.getValeur() << endl;
                        /*tableau[0] += itFindO3->second;
                        tableau[1] += itFindSO2->second;
                        tableau[2] += itFindNO2->second;
                        tableau[3] += itFindPM10->second;*/
                    }
                }

                compteur += 1;
            }
        }

        for(int i = 0; i < 4; ++i) {
            tableau[i] = tableau[i] / compteur;
        }
        double * ptr = tableau;
        return ptr;
    }
