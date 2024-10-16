#ifndef EX2_H
#define EX2_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath> 

using namespace std;

template <typename T>
class MatrixBase {
    protected:

        size_t lignes; 
        size_t colonnes; 
        vector<vector<T>> donnees; 

    public:

        MatrixBase();
        MatrixBase(size_t lignes, size_t colonnes);

        void ajouterElement(size_t ligne, size_t colonne, T valeur);
        T obtenirElement(size_t ligne, size_t colonne) const;

        size_t obtenirLignes() const;
        size_t obtenirColonnes() const;

        void afficher() const;
};

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
    static_assert(is_arithmetic<T>::value, "MatrixNumerical nécessite un type numérique");

    public:
        using MatrixBase<T>::MatrixBase; 

        T obtenirDeterminant() const;
        MatrixNumerical<T> obtenirInverse() const;

        MatrixNumerical<T> operator+(const MatrixNumerical<T>& autre) const;
        MatrixNumerical<T> operator-(const MatrixNumerical<T>& autre) const;
        MatrixNumerical<T> operator*(const MatrixNumerical<T>& autre) const;
        MatrixNumerical<T> operator/(const MatrixNumerical<T>& autre) const;

        static MatrixNumerical<T> obtenirIdentite(int taille);
};

// Définition des méthodes

template <typename T>
MatrixBase<T>::MatrixBase() : lignes(1), colonnes(1), donnees(1, vector<T>(1)) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t lignes, size_t colonnes) : lignes(lignes), colonnes(colonnes), donnees(lignes, vector<T>(colonnes)) {}

template <typename T>
void MatrixBase<T>::ajouterElement(size_t ligne, size_t colonne, T valeur) {
    if (ligne >= lignes || colonne >= colonnes) {
        throw out_of_range("Index hors limites");
    }
    donnees[ligne][colonne] = valeur;
}

template <typename T>
T MatrixBase<T>::obtenirElement(size_t ligne, size_t colonne) const {
    if (ligne >= lignes || colonne >= colonnes) {
        throw out_of_range("Index hors limites");
    }
    return donnees[ligne][colonne];
}

template <typename T>
size_t MatrixBase<T>::obtenirLignes() const {
    return lignes;
}

template <typename T>
size_t MatrixBase<T>::obtenirColonnes() const {
    return colonnes;
}

template <typename T>
void MatrixBase<T>::afficher() const {
    for (const auto& ligne : donnees) {
        for (const auto& elem : ligne) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

template <typename T>
T MatrixNumerical<T>::obtenirDeterminant() const {
    if (this->lignes != this->colonnes) {
        throw std::invalid_argument("La matrice doit être carrée pour calculer le déterminant.");
    }
    
    if (this->lignes == 2) {
        return this->donnees[0][0] * this->donnees[1][1] - this->donnees[0][1] * this->donnees[1][0];
    } else {
        cout << "Prochaine mise à jour pour Dim > 2" << "\n";
        return T();
    }
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::obtenirInverse() const {
    if (this->lignes != this->colonnes) {
        throw std::invalid_argument("La matrice doit être carrée pour calculer l'inverse.");
    }
    
    MatrixNumerical<T> inverse(this->lignes, this->colonnes);
    T determinant = obtenirDeterminant();
    if (std::fabs(determinant) < 1e-9) {
        throw std::runtime_error("La matrice est singulière et ne peut pas être inversée.");
    }
    
    if (this->lignes == 2) {
        inverse.donnees[0][0] = this->donnees[1][1] / determinant;
        inverse.donnees[0][1] = -this->donnees[0][1] / determinant;
        inverse.donnees[1][0] = -this->donnees[1][0] / determinant;
        inverse.donnees[1][1] = this->donnees[0][0] / determinant;
    } else {
        cout << "Prochaine mise à jour pour Dim > 2" << "\n";
    }

    return inverse;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& autre) const {
    if (this->lignes != autre.obtenirLignes() || this->colonnes != autre.obtenirColonnes()) {
        throw std::invalid_argument("Les matrices doivent avoir la même taille pour l'addition.");
    }
    
    MatrixNumerical<T> resultat(this->lignes, this->colonnes);
    for (size_t i = 0; i < this->lignes; ++i) {
        for (size_t j = 0; j < this->colonnes; ++j) {
            resultat.donnees[i][j] = this->donnees[i][j] + autre.donnees[i][j];
        }
    }
    return resultat;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& autre) const {
    if (this->lignes != autre.obtenirLignes() || this->colonnes != autre.obtenirColonnes()) {
        throw std::invalid_argument("Les matrices doivent avoir la même taille pour la soustraction.");
    }
    
    MatrixNumerical<T> resultat(this->lignes, this->colonnes);
    for (size_t i = 0; i < this->lignes; ++i) {
        for (size_t j = 0; j < this->colonnes; ++j) {
            resultat.donnees[i][j] = this->donnees[i][j] - autre.donnees[i][j];
        }
    }
    return resultat;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& autre) const {
    if (this->colonnes != autre.obtenirLignes()) {
        throw std::invalid_argument("Les matrices doivent être compatibles pour la multiplication.");
    }
    
    MatrixNumerical<T> resultat(this->lignes, autre.obtenirColonnes());
    for (size_t i = 0; i < this->lignes; ++i) {
        for (size_t j = 0; j < autre.obtenirColonnes(); ++j) {
            resultat.donnees[i][j] = 0;
            for (size_t k = 0; k < this->colonnes; ++k) {
                resultat.donnees[i][j] += this->donnees[i][k] * autre.donnees[k][j];
            }
        }
    }
    return resultat;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& autre) const {
    return *this * autre.obtenirInverse();
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::obtenirIdentite(int taille) {
    MatrixNumerical<T> identite(taille, taille);
    for (int i = 0; i < taille; ++i) {
        identite.donnees[i][i] = 1;
    }
    return identite;
}

#endif
