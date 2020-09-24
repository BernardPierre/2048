#include <math.h>
#include <time.h>
#include <biblio2048.h>
void InitialiserAleatoire()
{
     srand(time(nullptr));
}
Jeu2048::Jeu2048()
{

}

bool Jeu2048::JouerCoup(char in_direction)
{
    direction=in_direction;
    Deplacer();
    if(Calculer())
        Deplacer();
    CalculerScore();
    bool fin=RechercherFinDePartie();
    if(!fin)
        PlacerNouvelleTuile();
    nbCoups++;
    return fin;
}

int Jeu2048::ObtenirNbCoups()
{
    return nbCoups;
}

int Jeu2048::ObtenirScore()
{
    return score;
}

void Jeu2048::ObtenirGrille(int _Grille[][NB_VAL])
{
    for (int i=0;i<NB_VAL-1;i++) {
        for (int n=0;n<NB_VAL-1;n++) {
            _Grille[i][n] = laGrille [i][n];
        }
    }
}

void Jeu2048::InitialiserGrille(int uneGrille[][NB_VAL])
{
    for (int i=0;i<NB_VAL-1;i++) {
        for (int n=0;n<NB_VAL-1;n++) {
            uneGrille[i][n] = 0;
        }
    }
}

int Jeu2048::TirerAleatoire(const int _Mode)
{
    int retour;
    if (_Mode == POSITION) {
        retour = rand() % 4;
    }else {
retour = (((rand() % 2) +1 ) * 2);
}
      return retour;
}


void Jeu2048::PlacerNouvelleTuile()
{
    int ligne;
    int colonne;

    ligne = TirerAleatoire(POSITION);
    colonne = TirerAleatoire(POSITION);
    while (laGrille[ligne][colonne] != 0) {
        laGrille[ligne][colonne] = TirerAleatoire(TUILE);
    }
}


int CalculerScore(int uneGrille[][NB_VAL])
{
    int somme = 0;

    for (int i=0;i<NB_VAL-1;i++) {
        for (int n=0;n<NB_VAL-1;n++) {
            somme= somme + uneGrille[i][n];
        }
    }

    return somme;
}

bool Jeu2048::RechercherFinDePartie()
{
    bool fin;
    int cpt = 0;
    int n;

    for (int i=0;i<NB_VAL-1;i++) {
        for (n=0;n<NB_VAL-1;n++) {
            if (laGrille[i][n] == 2048) {
                fin = true;
            }
            if (laGrille[i][n] == 0) {
                cpt ++;
            }
        }
    }
    if (cpt == 0) {
        fin = true;
    }

    return fin;
}


bool Jeu2048::Calculer()
{
    int ligne;
    int colonne;
    bool retour = false;

    switch (direction) {
        case 'G':
            for (ligne=0;ligne<NB_VAL-1;ligne++) {
                for (colonne=1;colonne<NB_VAL-2;colonne++) {
                    if (laGrille[ligne][colonne]== laGrille[ligne][colonne+1]) {
                        laGrille[ligne][colonne] = laGrille[ligne][colonne]*2;
                        laGrille[ligne][colonne+1] = 0;
                        retour = true;
                    }
                }
            }
        break;
        case 'D':
            for (ligne=0;ligne<NB_VAL-1;ligne++) {
                for (colonne=1;colonne>NB_VAL-2;colonne--) {
                    if (laGrille[ligne][colonne]==laGrille[ligne][colonne-1]) {
                        laGrille[ligne][colonne] = laGrille[ligne][colonne]*2;
                        laGrille[ligne][colonne-1] = 0;
                        retour = true;
                    }
                }
            }
        break;
        case 'B':
            for (colonne=0;colonne<NB_VAL-1;colonne++) {
                for (ligne=1;ligne>NB_VAL-2;ligne--) {
                    if (laGrille[ligne][colonne]==laGrille[ligne-1][colonne]) {
                        laGrille[ligne][colonne] = laGrille[ligne][colonne]*2;
                        laGrille[ligne-1][colonne] = 0;
                        retour = true;
                    }
                }
            }
        break;
        case 'H':
            for (colonne=0;colonne<NB_VAL-1;colonne++) {
                for (ligne=0;ligne<NB_VAL-2;ligne++) {
                    if (laGrille[ligne][colonne]== laGrille[ligne+1][colonne]) {
                        laGrille[ligne][colonne] = laGrille[ligne][colonne]*2;
                        laGrille[ligne+1][colonne] = 0;
                        retour = true;
                    }
                }
            }
        break;
    }

    return retour;
}

void Jeu2048::Deplacer()
{
    int indice;
    int ligne;
    int colonne;
    bool retour = false;
    for (indice=0;indice<NB_VAL - 1;indice++) {
        switch (direction) {
            case 'G':
                for (ligne=0;ligne<NB_VAL-1;ligne++) {
                    for (colonne=1;colonne<NB_VAL-2;colonne++) {
                        if (laGrille[ligne][colonne]==0) {
                            laGrille[ligne][colonne] = laGrille[ligne][colonne+1];
                            laGrille[ligne][colonne+1] = 0;
                            retour = true;
                        }
                    }
                }
            break;
            case 'D':
                for (ligne=0;ligne<NB_VAL-1;ligne++) {
                    for (colonne=1;colonne>NB_VAL-2;colonne--) {
                        if (laGrille[ligne][colonne]==0) {
                            laGrille[ligne][colonne] = laGrille[ligne][colonne-1];
                            laGrille[ligne][colonne-1] = 0;
                            retour = true;
                        }
                    }
                }
            break;
            case 'B':
                for (colonne=0;colonne<NB_VAL-1;colonne++) {
                    for (ligne=1;ligne>NB_VAL-2;ligne--) {
                        if (laGrille[ligne][colonne]==0) {
                            laGrille[ligne][colonne] = laGrille[ligne-1][colonne];
                            laGrille[ligne-1][colonne] = 0;
                            retour = true;
                        }
                    }
                }
            break;
            case 'H':
                for (colonne=0;colonne<NB_VAL-1;colonne++) {
                    for (ligne=0;ligne<NB_VAL-2;ligne++) {
                        if (laGrille[ligne][colonne]==0) {
                            laGrille[ligne][colonne] = laGrille[ligne+1][colonne];
                            laGrille[ligne+1][colonne] = 0;
                            retour = true;
                        }
                    }
                }
            break;
        }
    }
}

int Jeu2048::CalculerScore()
{

}
