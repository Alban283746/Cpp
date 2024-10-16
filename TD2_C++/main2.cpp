#include "ex2.h"

int main() {
    try {
        MatrixNumerical<int> matrice1(2, 2);
        MatrixNumerical<int> matrice2(2, 2);

        matrice1.ajouterElement(0, 0, 1);
        matrice1.ajouterElement(0, 1, 2);
        matrice1.ajouterElement(1, 0, 3);
        matrice1.ajouterElement(1, 1, 4);

        matrice2.ajouterElement(0, 0, 5);
        matrice2.ajouterElement(0, 1, 6);
        matrice2.ajouterElement(1, 0, 7);
        matrice2.ajouterElement(1, 1, 8);

        cout << "Matrice 1:" << endl;
        matrice1.afficher();
        cout << "Matrice 2:" << endl;
        matrice2.afficher();

        MatrixNumerical<int> somme = matrice1 + matrice2;
        cout << "Somme des matrices:" << endl;
        somme.afficher();

        MatrixNumerical<int> difference = matrice1 - matrice2;
        cout << "Différence des matrices:" << endl;
        difference.afficher();

        MatrixNumerical<int> produit = matrice1 * matrice2;
        cout << "Produit des matrices:" << endl;
        produit.afficher();

        cout << "Déterminant de matrice1: " << matrice1.obtenirDeterminant() << endl;

        MatrixNumerical<int> inverse = matrice1.obtenirInverse();
        cout << "Inverse de matrice1:" << endl;
        inverse.afficher();

        MatrixNumerical<int> identite = MatrixNumerical<int>::obtenirIdentite(2);
        cout << "Matrice identité 2x2:" << endl;
        identite.afficher();

    } catch (const exception& e) {
        cerr << "Erreur: " << e.what() << endl;
    }

}