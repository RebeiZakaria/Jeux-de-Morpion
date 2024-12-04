#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED
#include <vector>

#include "Joueur.h"


class Jeux {
private:
    Joueur joueur1;
    Joueur joueur2;
    vector<vector<char>> grille; // La grille de jeu
    int taille;                  // Taille de la grille (ex: 3 pour 3x3)
    int tour;                    // 0 pour joueur1, 1 pour joueur2

public:
    // Constructeur
    Jeux(Joueur j1, Joueur j2, int tailleGrille);

    // Méthodes
    void afficherGrille();      // Afficher la grille
    void jouerTour();           // Gérer un tour
    bool verifierVictoire();    // Vérifier si un joueur a gagné
    void lancer();              // Lancer le jeu
};

// Implémentation
Jeux::Jeux(Joueur j1, Joueur j2, int tailleGrille)
    : joueur1(j1), joueur2(j2), taille(tailleGrille), tour(0) {
    // Initialiser une grille vide (remplie de cases vides ' ')
    grille = vector<vector<char>>(taille, vector<char>(taille, ' '));
}

void Jeux::afficherGrille() {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            cout << (grille[i][j] == ' ' ? '.' : grille[i][j]); // Afficher . pour les cases vides
            if (j < taille - 1) cout << "|";
        }
        cout << endl;
        if (i < taille - 1) cout << string(taille * 2 - 1, '-') << endl; // Séparateurs
    }
}

void Jeux::jouerTour() {
    Joueur joueurActuel = (tour % 2 == 0) ? joueur1 : joueur2;
    char symbole = joueurActuel.getSymbole();
    cout << "Tour de " << joueurActuel.getNom() << " (" << symbole << "). Entrez une position (ligne colonne) : ";

    int ligne, colonne;
    cin >> ligne >> colonne;

    // Vérification de la validité de la position
    while (ligne < 0 || ligne >= taille || colonne < 0 || colonne >= taille || grille[ligne][colonne] != ' ') {
        cout << "Position invalide. Réessayez : ";
        cin >> ligne >> colonne;
    }

    grille[ligne][colonne] = symbole; // Placer le symbole
    tour++; // Changer de tour
}

bool Jeux::verifierVictoire() {
    char symboleActuel = (tour % 2 == 0) ? joueur2.getSymbole() : joueur1.getSymbole();

    // Vérifier les lignes et colonnes
    for (int i = 0; i < taille; i++) {
        if (all_of(grille[i].begin(), grille[i].end(), [symboleActuel](char c) { return c == symboleActuel; })) return true;
        if (all_of(grille.begin(), grille.end(), [i, symboleActuel](vector<char> &row) { return row[i] == symboleActuel; })) return true;
    }

    // Vérifier les diagonales
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < taille; i++) {
        if (grille[i][i] != symboleActuel) diag1 = false;
        if (grille[i][taille - i - 1] != symboleActuel) diag2 = false;
    }

    return diag1 || diag2;
}

void Jeux::lancer() {
    cout << "----- Début du jeu -----" << endl;

    // Boucle principale du jeu
    while (true) {
        afficherGrille(); // Afficher la grille
        jouerTour();      // Tour d'un joueur

        // Vérifier si le joueur actuel a gagné
        if (verifierVictoire()) {
            afficherGrille(); // Montrer l'état final
            cout << "Félicitations, " << ((tour % 2 == 0) ? joueur2.getNom() : joueur1.getNom()) << " a gagné !" << endl;
            break;
        }

        // Vérifier si la grille est pleine (match nul)
        if (tour == taille * taille) {
            afficherGrille(); // Montrer l'état final
            cout << "Match nul !" << endl;
            break;
        }
    }
}



#endif // JEUX_H_INCLUDED
