#if ! defined ( ATTRIBUTMESURE_H )
#define ATTRIBUTMESURE_H
#include <string>
#include <iostream>
using namespace std; 

class AttributMesure {

public:
	string getNomGaz() const;

	string getUnite() const;

	string getDescription() const;

	void setNomGaz(const string nomGaz);

	void setUnite(const string unite);

	void setDescription(const string description);

	AttributMesure& operator=(const AttributMesure& unAttributMesure);

	AttributMesure(const AttributMesure& unAttributMesure);

	AttributMesure();

	virtual ~AttributMesure();

protected:

	string m_nomGaz;
	string m_unite;
	string m_description;
};
#endif

