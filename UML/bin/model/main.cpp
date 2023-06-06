#include <iostream>
#include "Fournisseur.h"
#include "Particulier.h"
#include "AgenceGouvernementale.h"
#include "Database.h"
#include "Purificateur.h"
#include "Mesure.h"
#include "Services.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
/**
 * @file main.cpp
 * 
 */

#ifdef MAP
#include <iostream>
#define construction(p) (std::cout << "Appel au constructeur de <Graph>"\
 << " avec this = " << p << std::endl)
#define constructionCopie(p) (std::cout << "Appel au constructeur"\
 << " par copie de <Graph> avec this = " << p << std::endl)
#define destruction(p) (std::cout << "Appel au destructeur de <Graph>"\
 << " avec this = " << p << std::endl)
#else
#define construction(p) ((void)0)
#define constructionCopie(p) ((void)0)
#define destruction(p) ((void)0)
#endif

#ifdef TRACE
#include <iostream>
#define debug(expression) (std::cout << __FILE__ << ":" << __LINE__ << \
" -> " << (expression) << std::endl)
#else
#define debug(expression) ((void)0)
#endif

int main(int argc, char** argv) {
    Database *data = new Database();
    //cout << "création de la data base: ok" << endl;
    data->InitCapteurs();
    //cout << "initialisation des capteurs: ok" << endl;
    Services *s = new Services();
    //cout << "création des services: ok" << endl;
    unordered_map<string, Capteur> capt = data->getMCapteurs();
    //cout << "création de l'unordered_map des capteurs: ok" << endl;
    string sensorSearch;
    cout << "Entrez l'Identifiant d'un Capteur pour vérifier s'il est Fonctionnel: ";
    cin >> sensorSearch;
    unordered_map<string, Capteur>::iterator it = capt.find(sensorSearch);
    //cout << "création de l'itérateur pour la map: ok" << endl;
     if(it == capt.end()) {
         cout << "erreur: le sensor n'est pas trouvé" << endl;
         return 0;
     }
    Capteur c = it->second;
    cout << "Capteur ID: " << c.getId() << endl;
    bool avant = c.getEstFonctionnel();
    if(avant == 1)
        cout << "Le capteur est initialement considéré comme: Fonctionnel" << endl;
    else
        cout << "Le capteur est initialement considéré comme: Dysfonctionnel" << endl;

    auto t1 = high_resolution_clock::now();
    bool b = s->verifierEtatCapteur(c, *data, 1);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms_double = t2 - t1;
    cout << "*** verifierEtatCapteur()'s CPU time = "<< ms_double.count()/1000.0 << " s ***" << endl;

    if(b == 0 && avant == 1)
        cout << "Le capteur est encore considéré comme: Fonctionnel\n\n" << endl;
    else if(b == 0 && avant == 0)
        cout << "Le capteur est désormais considéré comme: Fonctionnel\n\n" << endl;
    else if(b == 1 && avant == 0)
        cout << "Le capteur est encore considéré comme: Dysfonctionnel\n\n" << endl;
    else if(b == 1 && avant == 1)
        cout << "Le capteur est désormais considéré comme: Dysfonctionnel\n\n" << endl;

    unordered_map<string, Capteur> listeDesCapteurs = data->getMCapteurs();
    /*for(const auto& capteurBoucle : listeDesCapteurs) {
        cout << "Capteur: " <<capteurBoucle.first << endl;
    }*/
    cout << "Entrez entrer la latitude du point géogrpahique souhaité: ";
    double lat; 
    cin >> lat; 
    cout << endl; 
    cout << "Entrez entrer la longitude du point géogrpahique souhaité: ";
    double lon; 
    cin >> lon; 
    // Cordonées d'un capteur du fichier : Coordonnee(44.0, 2);
    Coordonnee coo = Coordonnee(lat, lon);
    cout << endl; 
    cout << "Entrez la date à laquelle vous souhaitez obtenir la qualité de l'air sous le format dd/MM/yyyy HH:mm : ";
    string date ; 
    cin >> date; 
    string heure; 
    cin >> heure; 

    date =  date + " " + heure; 
    //string date = "01/01/2019 12:00";

    // Affichage lié à obtenirQualiteAirPosition

    t1 = high_resolution_clock::now();
    double *res = s->obtenirQualiteAirPosition(*data, coo, date);
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "*** obtenirQualiteAirPosition()'s CPU time = "<< ms_double.count()/1000.0 << " s ***" << endl;

    cout << endl; 
    cout << "Voici les concentrations des gazs le " << date << ":" << endl; 
    cout << endl; 
    cout << "Mesure O3: " << res[0] << " μg/m3" << endl;
    cout << "Mesure NO2: " << res[1] << " μg/m3" << endl;
    cout << "Mesure SO2: " << res[2] << " μg/m3" << endl;
    cout << "Mesure PM10: " << res[3] << " μg/m3" << endl;
    cout << endl; 

    return 0;
}