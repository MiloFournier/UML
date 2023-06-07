    #include "Database.h"

    //fichiers

    /*
    // 1 seul capteur
    string prov = "../../tables/providers.csv";
    string clean = "../../tables/cleaners.csv";
    string part = "../../tables/jeuVide.csv";
    string meas = "../../tables/measurements01.csv";
    string sens = "../../tables/sensors01.csv";
    */

    // 0 capteur
    /*
    string prov = "../../tables/providers.csv";
    string clean = "../../tables/cleaners.csv";
    string part = "../../tables/jeuVide.csv";
    string meas = "../../tables/measurements02.csv";
    string sens = "../../tables/sensors02.csv";
    */

    // 3 capteurs avec les mêmes mesures et distance ok
    /*
    string prov = "../../tables/providers.csv";
    string clean = "../../tables/cleaners.csv";
    string part = "../../tables/jeuVide.csv";
    string meas = "../../tables/measurements04.csv";
    string sens = "../../tables/sensors03.csv";
    */

    // 3 capteurs avec les mêmes mesures mais distance PAS OK
    /*
    string prov = "../../tables/providers.csv";
    string clean = "../../tables/cleaners.csv";
    string part = "../../tables/jeuVide.csv";
    string meas = "../../tables/measurements04.csv";
    string sens = "../../tables/sensors04.csv";
    */


    // 3 capteurs, Sensor0 = fonctionnel mais Sensor1 = dysfonctionnel
    // car mesures de Sensor1 = [1000, 1000, 1000, 1000]
    string prov = "../../tables/providers.csv";
    string clean = "../../tables/cleaners.csv";
    string part = "../../tables/jeuVide.csv";
    string meas = "../../tables/measurements05.csv";
    string sens = "../../tables/sensors05.csv";

    //test06 il suffit de décommenter la ligne 64 du main: on passe de dysfonctionnel à fonctionnel

    bool Database::FinFichier(ifstream& fic)
    {
        return fic.eof();
    }

    void Database::LireFournisseurs(){
        ifstream fic;
        fic.open(prov);

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
                m_fournisseurs.insert({recupProvider, four});

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
        fic.close();
    }

    Purificateur Database::LirePurificateurs (string id){
        ifstream fic; 
        fic.open(clean);
        string lat;
        string lon;
        string deb;
        string fin;

        /*recherche dans le fichier des informations de notre cleaner*/
        bool trouve = false;

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
        fic.close();
        return pur;
    }

    void Database::LireParticuliers(){
        ifstream fic;
        fic.open(part);

        /*recuperer les informations depuis le fichier*/
        while(FinFichier(fic) == false){
            if(fic.eof()) break; 
            string recupUser;
            string recupSensor;
            string test; 
            getline(fic, recupUser,';');
            getline(fic, recupSensor,';');
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
        fic.open(meas);
        streampos posDebut = fic.tellg();
        fic.seekg(0, ios::end);
        streampos posFin = fic.tellg();
        if (posFin == posDebut) {
            return;
        } else {
            fic.seekg(0, ios::beg);
            string date;
            string test;
            string type;
            string mesure;

            while (FinFichier(fic) == false) {
                if (fic.eof()) break;
                getline(fic, date, ';');
                getline(fic, test, ';');

                // On a trouvé le capteur
                if (test == idCapteur) {
                    getline(fic, type, ';');
                    getline(fic, mesure, ';');
                    getline(fic, test);
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
                } else {
                    getline(fic, test);
                }
            }
        }
        fic.close();
}

    Capteur Database::LireCapteurs (string id){
        ifstream fic;
        fic.open(sens);
        streampos posDebut = fic.tellg();
        fic.seekg(0, ios::end);
        streampos posFin = fic.tellg();
        Capteur cap;
        if (posFin == posDebut) {
            return cap;
        } else {
            fic.seekg(0, ios::beg);
            string lat;
            string lon;

            /*recherche dans le fichier des informations de notre cleaner*/
            bool trouve = false;

            while (trouve == false && FinFichier(fic) == false) {
                if (fic.eof()) break;
                string test;
                getline(fic, test, ';');
                /*si on a trouve le bon cleaner on cree l'objet*/
                if (test == id) {
                    getline(fic, lat, ';');
                    getline(fic, lon, ';');
                    getline(fic, test);
                    trouve = true;

                    /*sinon on passe au prochain purificateur*/
                } else {
                    getline(fic, test, ';');
                    getline(fic, test, ';');
                }
            }
            if (trouve == false) {
                return Capteur();
            }

            Coordonnee cor = Coordonnee(lat, lon);

            Capteur cap = Capteur(cor, id, true);

            /*ensuite on ajoute les mesures dans le capteur*/
            lireMesures(id);
        }
        fic.close();
        return cap;
    }

    bool Database::InitCapteurs() {
        ifstream fic;
        fic.open(sens);
        streampos posDebut = fic.tellg();
        fic.seekg(0, ios::end);
        streampos posFin = fic.tellg();
        if (posFin == posDebut) {
            fic.close();
            return false;
        } else {
            fic.seekg(0, ios::beg);
            string lat;
            string lon;
            string test;
            string saut;
            int i = 0;
            while (FinFichier(fic) == false) {
                if (fic.eof()) break;
                getline(fic, test, ';');
                /*si on a trouve le bon cleaner on cree l'objet*/
                getline(fic, lat, ';');
                getline(fic, lon, ';');
                getline(fic, saut);
                Coordonnee cor = Coordonnee(lat, lon);

                Capteur cap = Capteur(cor, test, true);
                m_capteurs.insert({test, cap});
                lireMesures(test);
                i++;
            }
            fic.close();
            return true;
        }
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

    Database::Database ()
    {
        LireFournisseurs();
    }

    Database::~Database( )
    {}