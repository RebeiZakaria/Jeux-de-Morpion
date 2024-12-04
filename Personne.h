#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED


class Personne
{
protected:
    string nom;
    string prenom;
public:
    Personne(string, string); // Constructeur
    void afficherInfo();      // Déclaration de la méthode
};

// Implémentation du constructeur
Personne::Personne(string n, string p)
{
    nom = n;
    prenom = p;
}

// Implémentation de la méthode afficherInfo
void Personne::afficherInfo()
{
    cout << "Nom : " << nom << endl;
    cout << "Prénom : " << prenom << endl;
}

#endif // PERSONNE_H_INCLUDED
