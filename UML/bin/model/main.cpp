#include <iostream>
#include "Fournisseur.h"
#include "Particulier.h"
#include "AgenceGouvernementale.h"
#include "Database.h"
#include "Purificateur.h"
#include "Mesure.h"
#include "Services.h"

using namespace std;

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
    bool b = s->verifierEtatCapteur(c, *data, true);

    if(b == 0 && avant == 1)
        cout << "Le capteur est encore considéré comme: Fonctionnel\n\n" << endl;
    else if(b == 0 && avant == 0)
        cout << "Le capteur est désormais considéré comme: Fonctionnel\n\n" << endl;
    else if(b == 1 && avant == 0)
        cout << "Le capteur est encore considéré comme: Dysfonctionnel\n\n" << endl;
    else if(b == 1 && avant == 1)
        cout << "Le capteur est désormais considéré comme: Dysfonctionnel\n\n" << endl;



    unordered_map<string, Capteur> listeDesCapteurs = data->getMCapteurs();
    //for(unordered_map<string, Capteur>::iterator cap = data->getMCapteurs().begin(); cap != data->getMCapteurs().end(); cap++){
    for(const auto& capteurBoucle : listeDesCapteurs) {
        cout << "Capteur: " <<capteurBoucle.first << endl;
    }

    Coordonnee coo = Coordonnee(44.0, -1.0);
    string date = "2019-01-01 12:00:00";

    // Affichage lié à obtenirQualiteAirPosition
    double *res = s->obtenirQualiteAirPosition(data, coo, date);
    cout << "Mesure O3: " << res[0] << endl;

    return 0;
}




