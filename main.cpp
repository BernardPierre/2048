#include <iostream>
#include <biblio2048.h>

using namespace std;

void afficherGrille(Jeu2048 _leJeu)
{
    int laGrille[NB_VAL][NB_VAL];
    _leJeu.ObtenirGrille(laGrille);
    int Score = _leJeu.ObtenirScore();
    int leNombresDeCoups = _leJeu.ObtenirNbCoups();

    system("clear");

    cout << "Score : " << Score << " | Nombres de coups : " << leNombresDeCoups << " |" << endl;
    cout <<'+';

    for (int colonne=0;colonne < 4;colonne ++) {
        for (int ligne = 0;ligne < 4;ligne ++) {
            cout << setfill('-') << setw(7)<<'+';
        }
        cout << '+' << ' ' <<endl;

        for (int ligne = 0;ligne < 5;ligne ++) {
            cout << '|' << setw(6) << setfill(' ') << laGrille[ligne][colonne] << left;
        }
        cout << ' ' << endl;

    }
    for (int ligne = 0;ligne < 4;ligne ++) {
        cout << setfill('-') << setw(7)<<'+';
    }
    cout << ' ' << endl;

    cout << "Votre déplacement : H (haut, B (bas), D (droite, G (gauche) : ";

}

int main()
{
    int laGrille[NB_VAL][NB_VAL];
    bool finDePartie;
    char direction;
    int nbCoups;
    int score;

    Jeu2048 leJeu;


    afficherGrille(leJeu);




    return 0;
}



