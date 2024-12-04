#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "Personne.h"

#include <vector>
#include <algorithm> // Pour std::find

class Joueur:public Personne
{
private:
    char symbole;
public:
    Joueur(string,string,char);
    bool validerSymbole(char);
    void afficherSymbole_1();
    void afficherSymbole_2();
     // Getter pour le nom
    string getNom() const {
        return nom;
    }

    // Getter pour le symbole
    char getSymbole() const {
        return symbole;
    }

};

Joueur::Joueur(string n,string p,char s):Personne(n,p)
{
    symbole=s;
}

bool Joueur::validerSymbole(char symboleChoisi)
{
    vector<char> symbolesValides={'X','O','*','+'};
    // Vérifie si le symbole appartient à la liste
    if (find(symbolesValides.begin(), symbolesValides.end(),symboleChoisi) != symbolesValides.end())
    {
        symbole = symboleChoisi; // Le symbole est valide
        return true;
    }
    else
    {
        cout<<"Symbole invalide ! Veuillez choisir parmi :";
        for (char s:symbolesValides)
            cout<<s<<" ";
        cout<<endl;
        return false;
    }
}

void Joueur::afficherSymbole_1()
{
    cout<<"Symbole du joueur 1: "<< symbole<<endl;
}

void Joueur::afficherSymbole_2()
{
    cout<<"Symbole du joueur 2: "<< symbole<<endl;
}


#endif // JOUEUR_H_INCLUDED
