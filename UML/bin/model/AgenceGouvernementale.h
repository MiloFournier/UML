#if ! defined ( AGENCEGOUVERNEMENTALE_H )
#define AGENCEGOUVERNEMENTALE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>
#include <fstream>
#include "Acteur.h"

class AgenceGouvernementale : public Acteur {

    public:

        AgenceGouvernementale(std::string id);
        ~AgenceGouvernementale();

};

#endif // AGENCEGOUVERNEMENTALE_H