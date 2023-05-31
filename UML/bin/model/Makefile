# Ajouter dans SRCS obtenirQualiteAirPosition.cpp, quantifierImpactPurificateur.cpp, verifierEtatCapteur.cpp, Services.cpp
CC = g++
CFLAGS = -std=c++11 -Wall -ggdb
LDFLAGS =
EXEC = main

# List of source files
SRCS = Acteur.cpp AgenceGouvernementale.cpp Appareil.cpp AttributMesure.cpp Capteur.cpp Coordonnee.cpp Database.cpp Fournisseur.cpp Mesure.cpp Particulier.cpp Purificateur.cpp main.cpp Services.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)