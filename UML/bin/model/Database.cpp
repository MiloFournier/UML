    /*************************************************************************
                             Flux -  description
                                -------------------
        début                : 10/05/23
        copyright            : B3122 B3126
    *************************************************************************/

    //---------- Réalisation de la classe <LireFichier> (fichier LireFichier.cpp) ------------

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système

    //------------------------------------------------------ Include personnel
    #include "Database.h"
    #include <string>

    //------------------------------------------------------------- Constantes

    //----------------------------------------------------------------- PUBLIC

    //----------------------------------------------------- Méthodes publiques
    bool Database::FinFichier(ifstream& fic)
    {
        return fic.eof();
    }


    void Database::LireFournisseurs(){
        ifstream fic;
        fic.open("../../tables/providers.csv");

        //cout << "Je suis la (LireFournisseurs) !" << endl;
        /*recuperer les informations depuis le fichier*/
        while (FinFichier(fic) == false){ 
            string recupProvider = "null";
            string recupCleaner = "null";
            getline(fic, recupProvider, ';');
            getline(fic, recupCleaner, ';');

            Coordonnee co = Coordonnee();
            Purificateur puri = Purificateur();
            puri.setId(recupCleaner);

            unordered_map<string, Fournisseur>::iterator it = m_fournisseurs.find(recupProvider);

            /*si le fournisseur n'existe pas encore dans la base de donnees, on le cree*/
            if (it == m_fournisseurs.end())
            {
                //alors la liste de cleaner de ce fournisseur n'a pas encore ete cree
                
                list<Purificateur> m_listePurificateurs = {puri};
                Fournisseur four = Fournisseur(recupProvider, m_listePurificateurs);
                m_fournisseurs.insert({recupProvider, four}); // Ajout de cette ligne

                //si le fournisseur existe deja, alors on rajoute ce purificateur a sa liste deja existante
            }
            else
            {
                list<Purificateur> li = it->second.getListePurificateurs();
                li.push_back(puri);
                it->second.setListePurificateurs(li);
            }
        }


        unordered_map<string, Fournisseur>::iterator itera = m_fournisseurs.begin();
        m_fournisseurs.erase(itera);

        for (unordered_map<string, Fournisseur>::iterator it = m_fournisseurs.begin(); it != m_fournisseurs.end(); it++){
            
            list<Purificateur> listPuri = it->second.getListePurificateurs();
            for(list<Purificateur>::iterator iList = listPuri.begin(); iList != listPuri.end(); iList++){
                Purificateur puri = LirePurificateurs(iList->getId());
                iList->setArret(puri.getArret());
                iList->setDemarrage(puri.getDemarrage());
                iList->setCoordonnee(puri.getCoordonnee());
            }
            it->second.setListePurificateurs(listPuri);
            
        }
    
   
        //cout << "J'ai terminé avec LireFournisseurs' !" << endl;
        fic.close();
    }

        //----- Fin de LireFournisseur

    Purificateur Database::LirePurificateurs (string id){
        ifstream fic; 
        fic.open("../../tables/cleaners.csv");
        string lat;
        string lon;
        string deb;
        string fin;

        /*recherche dans le fichier des informations de notre cleaner*/
        bool trouve = false;

        //cout << "Je suis la (LirePurificateurs) !" << endl;

        while(trouve ==false && FinFichier(fic) == false){
            if(fic.eof()) break; 
            string test;
            getline(fic, test, ';');
            /*si on a trouve le bon cleaner on cree l'objet*/
            if(test == id){
                getline(fic, lat, ';');
                getline(fic, lon, ';');
                getline(fic, deb, ';');
                getline(fic, fin, ';');
                trouve = true;

            /*sinon on passe au prochain purificateur*/
            }else{
                getline(fic, test, ';');
                getline(fic, test, ';');
                getline(fic, test, ';');
                getline(fic, test, ';');
            }
        }

        if(trouve == false){
            return Purificateur();
        }

        

        Coordonnee cor = Coordonnee(lat, lon);
        Purificateur pur = Purificateur(cor, id, deb, fin);
        //cout << "J'ai terminé avec LirePurificateurs !" << endl;

        fic.close();
        return pur;
    }//----- Fin de LirePurificateur

    void Database::LireParticuliers(){
        ifstream fic;
        fic.open("../../tables/jeuVide.csv");

        /*recuperer les informations depuis le fichier*/
        while(FinFichier(fic) == false){
            if(fic.eof()) break; 
            string recupUser;
            string recupSensor;
            string test; 
            getline(fic, recupUser,';');
            getline(fic, recupSensor,';');
            //cout << "recupSensor: " << recupSensor << endl;
            getline(fic, test); 
            
            Capteur cap = LireCapteurs(recupSensor);

            m_capteurs.insert({cap.getId(), cap}); 

            unordered_map<string, Particulier>::iterator it = m_particuliers.find(recupUser);

            /*si le particulier n'existe pas encore dans la base de donnees, on le cree*/
            if(it == m_particuliers.end()){
                /*alors la liste de capteurs de ce particulier n'a pas encore ete cree*/
                list<Capteur> m_listeCapteurs = {cap};
                /*L'utilisateur est cree en aillant 0 points et on part du principe qu'il est honnete*/
                Particulier part = Particulier(recupUser, 0, true);
                part.setListeCapteurs(m_listeCapteurs); 
                m_particuliers.insert({recupUser, part});

            /*si le fournisseur existe deja, alors on rajoute ce purificateur a sa liste deja existante*/    
            }else{
                list <Capteur> li = it->second.getListeCapteurs();
                li.push_back(cap);
                it->second.setListeCapteurs(li);
            }
            
        }

        unordered_map<string, Particulier>::iterator itera = m_particuliers.begin();
        m_particuliers.erase(itera);

        fic.close();
    }

    void Database::lireMesures(string idCapteur) {

        ifstream fic;
        fic.open("../../tables/mesuresVide.csv");

        string date;
        string test;
        string type;
        string mesure;

        while(FinFichier(fic) == false) {
            if(fic.eof()) break; 
            getline(fic, date, ';');
            getline(fic, test, ';');

            // On a trouvé le capteur
            if (test == idCapteur) {
                getline(fic, type, ';');
                getline(fic, mesure, ';');
                getline(fic, test); 
                //cout << "lecture" << endl;
                unordered_map<string, Capteur>::iterator it = m_capteurs.find(idCapteur);
                
                Mesure m = Mesure(date, mesure, type);

                if (type == "O3") {
                    it->second.setLMesures_O3(date, m);
                } else if (type == "SO2") {
                    it->second.setLMesures_SO2(date, m);
                } else if (type == "NO2") {
                    it->second.setLMesures_NO2(date, m);
                } else if (type == "PM10") {
                    it->second.setLMesures_PM10(date, m);
                }
            }
        }
        fic.close();
}


    Capteur Database::LireCapteurs (string id){
        //cout << "je suis dans LireCapteurs" << endl;
        ifstream fic; 
        fic.open("../../tables/jeuData.csv");
        string lat;
        string lon;

        //cout << "open fichiers ok" << endl;

        /*recherche dans le fichier des informations de notre cleaner*/
        bool trouve = false;

        while(trouve == false && FinFichier(fic) == false){
            if(fic.eof()) break; 
            string test;
            getline(fic, test, ';');
            //cout << "test: " << test << endl;
            //cout << "id: " << id << endl;
            /*si on a trouve le bon cleaner on cree l'objet*/
            if(test == id){
                //cout << "test == id" << endl;
                getline(fic, lat, ';');
                getline(fic, lon, ';');
                getline(fic, test); 
                trouve = true;

            /*sinon on passe au prochain purificateur*/
            }else{
                getline(fic, test, ';');
                getline(fic, test, ';');
                //getline(fic, test); 
            }
        }

        if(trouve == false){
            return Capteur();
        }
        fic.close();

        Coordonnee cor = Coordonnee(lat, lon);

        Capteur cap = Capteur(cor, id, true);

        /*ensuite on ajoute les mesures dans le capteur*/
        lireMesures(id);
        
        return cap; 
        
    }//----- Fin de LireCapteurs

    void Database::InitCapteurs() {
        ifstream fic; 
        fic.open("../../tables/jeuData.csv");
        string lat;
        string lon;
        string test;
        string saut;
        int i = 0;
        while(FinFichier(fic) == false){
            if(fic.eof()) break; 
            getline(fic, test, ';');
            /*si on a trouve le bon cleaner on cree l'objet*/
                getline(fic, lat, ';');
                getline(fic, lon, ';');
                getline(fic, saut);
                //cout << lat << endl;
                //cout << lon << endl;
                //cout << test<< endl;
                Coordonnee cor = Coordonnee(lat, lon);
                //cout << "coord" << endl;

                Capteur cap = Capteur(cor, test, true);
                //cout << "capt" << endl;
                m_capteurs.insert({test, cap});
                lireMesures(test);
                //cout << "lire" << endl;
                i++;
        }

        fic.close();

        

        /*ensuite on ajoute les mesures dans le capteur*/
        


        
        
    }

    unordered_map<string, Capteur> Database::getMCapteurs(){
        return m_capteurs;
    }

    unordered_map<string, Fournisseur> Database::getMFournisseurs(){
        return m_fournisseurs;
    }

    unordered_map<string, Particulier> Database::getMParticuliers(){
        return m_particuliers;
    }

    //-------------------------------------------- Constructeurs - destructeur

    Database::Database ()
    // Algorithme :
    //
    {
        LireFournisseurs();
        //LireParticuliers();
    #ifdef MAP
        cout << "Appel au constructeur de <Database>" << endl;
    #endif
    } //----- Fin de Flux


    Database::~Database( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Database>" << endl;
    #endif
    } //----- Fin de ~Flux


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

