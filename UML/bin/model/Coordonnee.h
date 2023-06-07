#if ! defined ( COORDONNEE_H )
#define COORDONNEE_H

class Coordonnee {

public:
	double getLatitude() const;

	double getLongitude() const;

	void setLatitude(const double latitude);

	void setLongitude(const double longitude);

	Coordonnee& operator=(const Coordonnee& uneCoordonnee);

	Coordonnee(const Coordonnee& uneCoordonnee);

	Coordonnee(const double latitude, const double longitude);

    Coordonnee(const std::string& latitude, const std::string& longitude);

	Coordonnee();

	virtual ~Coordonnee();

protected:
	double m_latitude;
	double m_longitude;
};
#endif