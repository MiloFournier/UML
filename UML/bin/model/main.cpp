#include <iostream>
#include "Fournisseur.h"
#include "Particulier.h"
#include "AgenceGouvernementale.h"
#include "Database.h"
#include "Purificateur.h"
#include "Mesure.h"

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

    // Affichage des fournisseurs
    unordered_map<string, Particulier> parti = data->getMParticuliers();
    cout << "Voici la liste des Particuliers" << endl; 
    for (unordered_map<string, Particulier>::iterator it = parti.begin(); it != parti.end(); ++it){
        cout << "hello" << endl;
        const string& particulierId = it->first;
        const Particulier& particulier = it->second;
        cout << "ID_particulier: " << particulierId << endl;
        list<Capteur>::iterator cap = it->second.getListeCapteurs().begin();
        cout << "Capteur qui nous interesse" << cap->getEstFonctionnel();
        //cout << "it->second : " << particulier;
        
    }
    
    // Autres informations du fournisseur si nécessaire

    return 0;
}




