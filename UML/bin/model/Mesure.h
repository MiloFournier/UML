#if ! defined ( MESURE_H )
#define MESURE_H

#include <string>
using namespace std; 

class Mesure {

public:
	string getDate() const;

	double getValeur() const;

	string getNomGaz() const;

	void setDate(const string& string);

	void setValeur(const double& valeur);

	void setNomGaz(const string& nomGaz);

	Mesure& operator=(const Mesure& uneMesure);

	bool operator==(const Mesure& uneMesure) const;

	bool operator<(const Mesure& uneMesure) const;

	Mesure(const Mesure& uneMesure);

	Mesure(const string& date, const string& valeur, const string& nomGaz);

	Mesure();

	virtual ~Mesure();

protected:
	string m_date;
	double m_valeur;
	string m_nomGaz;
};

#endif