#ifndef BIBLIO2048_H
#define BIBLIO2048_H
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
enum MODE_ALEATOIRE{
    POSITION,
    TUILE
};


#define NB_VAL 4

class Jeu2048{
private :
    int laGrille[NB_VAL][NB_VAL];
    char direction;
    int nbCoups;
    int score;

public:
    Jeu2048();
    bool JouerCoup(char in_direction);
    int ObtenirNbCoups();
    int ObtenirScore();
    void ObtenirGrille(int _Grille[][NB_VAL]);
    void InitialiserGrille(int uneGrille[][NB_VAL]);
private:
    int TirerAleatoire(const int _Mode);
    void PlacerNouvelleTuile();
    bool Calculer();
    void Deplacer();
    int CalculerScore();
    bool RechercherFinDePartie();
};

/*
void InitialiserAleatoire();


void afficherGrille(int uneGrille[][NB_VAL]);

void JouerCoup(int direction,int uneGrille[][NB_VAL]);
*/





#endif // BIBLIO2048_H
