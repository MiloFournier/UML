/*************************************************************************
                           Database  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Database> (fichier Database.h) ----------------
#if ! defined ( Database_H )
#define Database_H

using namespace std;
#include <iostream>
#include "Purificateur.h"
#include "Fournisseur.h"
#include "Particulier.h"
#include "Capteur.h"
#include "Coordonnee.h"
#include <map>
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Database>
//
//
//------------------------------------------------------------------------

class Database 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool FinFichier (ifstream & fic);
        // Mode d'emploi :
        //
        // Contrat :
        //

    Purificateur LirePurificateurs (string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void LireFournisseurs ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Capteur LireCapteurs (string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void LireParticuliers();
    // Mode d'emploi :
    //
    // Contrat :
    //
    void lireMesures(string idCapteur);

    unordered_map<string, Capteur> getMCapteurs();

    unordered_map<string, Fournisseur> getMFournisseurs();

    unordered_map<string, Particulier> getMParticuliers();

//-------------------------------------------- Constructeurs - destructeur
    Database ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Database ();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    std::unordered_map<string, Capteur> m_capteurs;
    std::unordered_map<string, Particulier> m_particuliers;
    std::unordered_map<string, Fournisseur> m_fournisseurs;
};

//-------------------------------- Autres définitions dépendantes de <Flux>
#endif // Flux_H

