#if ! defined ( Database_H )
#define Database_H

#include <iostream>
#include "Purificateur.h"
#include "Fournisseur.h"
#include "Particulier.h"
#include "Capteur.h"
#include "Coordonnee.h"
#include <map>
#include <string>
#include <fstream>

class Database 
{

public:
    bool FinFichier (ifstream & fic);

    Purificateur LirePurificateurs (string id);

    void LireFournisseurs ();

    Capteur LireCapteurs (string id);

    void LireParticuliers();

    void lireMesures(string idCapteur);

    bool InitCapteurs();

    unordered_map<string, Capteur> getMCapteurs();

    unordered_map<string, Fournisseur> getMFournisseurs();

    unordered_map<string, Particulier> getMParticuliers();

    Database ();

    virtual ~Database ();

protected:
    std::unordered_map<string, Capteur> m_capteurs;
    std::unordered_map<string, Particulier> m_particuliers;
    std::unordered_map<string, Fournisseur> m_fournisseurs;
};
#endif