#include <iostream>
#include "Particulier.h"
#include "Database.h"
#include "Purificateur.h"
#include "Services.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char** argv) {
    Database *data = new Database();
    bool bInit = data->InitCapteurs();
    if(!bInit) {
        cerr << "Erreur, il n'y a aucun capteur dans le fichier." << endl;
        return -1;
    } else {
        Services *s = new Services();
        unordered_map <string, Capteur> capt = data->getMCapteurs();
        string sensorSearch;
        cout << "Entrez l'Identifiant d'un Capteur pour vérifier s'il est Fonctionnel: ";
        cin >> sensorSearch;
        unordered_map<string, Capteur>::iterator it = capt.find(sensorSearch);
        if (it == capt.end()) {
            cout << "erreur: le sensor n'est pas trouvé" << endl;
            return 0;
        }
        Capteur c = it->second;
        cout << "Capteur ID: " << c.getId() << endl;

        //test 06
        //c.setEstFonctionnel(0);

        bool avant = c.getEstFonctionnel();
        if (avant == 1)
            cout << "Le capteur est initialement considéré comme: Fonctionnel" << endl;
        else
            cout << "Le capteur est initialement considéré comme: Dysfonctionnel" << endl;

        auto t1 = high_resolution_clock::now();
        bool b = s->verifierEtatCapteur(c, *data, 1);
        auto t2 = high_resolution_clock::now();
        duration<double, milli> ms_double = t2 - t1;
        cout << endl;
        cout << "*** verifierEtatCapteur()'s CPU time = " << ms_double.count() / 1000.0 << " s ***" << endl;

        if (b == 0 && avant == 1)
            cout << "Le capteur est encore considéré comme: Fonctionnel\n\n" << endl;
        else if (b == 0 && avant == 0)
            cout << "Le capteur est désormais considéré comme: Fonctionnel\n\n" << endl;
        else if (b == 1 && avant == 0)
            cout << "Le capteur est encore considéré comme: Dysfonctionnel\n\n" << endl;
        else if (b == 1 && avant == 1)
            cout << "Le capteur est désormais considéré comme: Dysfonctionnel\n\n" << endl;

        cout << "Entrez entrer la latitude du point géographique souhaité: ";
        double lat;
        cin >> lat;
        cout << endl;
        cout << "Entrez entrer la longitude du point géographique souhaité: ";
        double lon;
        cin >> lon;
        Coordonnee coo = Coordonnee(lat, lon);
        cout << endl;
        cout << "Entrez la date à laquelle vous souhaitez obtenir la qualité de l'air sous le format yyyy-dd-mm HH:mm:ss : ";
        string date;
        cin >> date;
        string heure;
        cin >> heure;

        date = date + " " + heure;

        t1 = high_resolution_clock::now();
        double *res = s->obtenirQualiteAirPosition(*data, coo, date);
        t2 = high_resolution_clock::now();
        ms_double = t2 - t1;
        cout << "*** obtenirQualiteAirPosition()'s CPU time = " << ms_double.count() / 1000.0 << " s ***" << endl;

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
}