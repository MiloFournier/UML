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
        //cout << "\n   \n   entrée dans la méthode verifierEtatCapteur: ok" << endl;
        //Database *data = new Database();
        //data->InitCapteurs();
        unordered_map<string, Capteur> listeDesCapteurs = data.getMCapteurs();
        // Parcours de tous les capteurs
        //cout << data->getMCapteurs().size() << endl;
        const auto& it = listeDesCapteurs.begin();
        //cout << "size de listeDesCapteurs: " << listeDesCapteurs.size() << endl;
        if(listeDesCapteurs.size() != 0)
            cout << "   distance aux autres capteurs: " << endl;
        for (const auto& capteurTest : listeDesCapteurs) {
        // Vérification de la distance entre capteurParam et capteurTest
            cout << "           " << capteurTest.second.getId() << ": " << capteurTest.second.calculDistance(capteurParam); //<< endl;
            if (capteurTest.second.calculDistance(capteurParam) < distanceDeVerification && capteurTest.second.calculDistance(capteurParam) != 0.0) {
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
        //cout << "\n   compteurErreurs: " << compteurErreurs << endl;
        //cout << "   compteur: " << compteur << endl;
        if (compteur>0){
            // Le cast est obligatoire sinon le résultat de la division est 0
            tauxErreur = (static_cast<double>(compteurErreurs) / compteur) * 100.0;
        }
        //cout << "   tauxErreur: " << tauxErreur << endl;
        bool dysfonctionnel = false;
        if (tauxErreur > 70.0) {
            dysfonctionnel = true;
        }
        if (dysfonctionnel){
            capteurParam.setEstFonctionnel(false); 
        } else {
            capteurParam.setEstFonctionnel(true); 
        }
        //cout << "   dysfonctionnel: " << dysfonctionnel << "\n\n" <<endl;
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
        string clef = it.first; // clef du capteur actuel
        Capteur valeur = it.second; // valeur du capteur actuel
        cout << "Coucou la clé" << valeur.getId() << endl;

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
    // code existant dans d'autres fichiers à insérer ici