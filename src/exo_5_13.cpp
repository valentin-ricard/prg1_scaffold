//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>


using namespace std;

void supprimerElement(int tableau[], size_t &longueur, size_t index) {
    for (size_t i = index; i < longueur; ++i) {
        tableau[i] = tableau[i + 1];
    }
    --longueur;
}

void supprimerValeur(int tableau[], size_t &longueur, int valeur) {
    for (size_t i = 0; i < longueur; ++i) {
        if (tableau[i] == valeur) {
            supprimerElement(tableau, longueur, i);
            // On réduit l'index pour ne pas sauter un élément
            --i;
        }
    }
}

void supprimerDoublons(int tableau[], size_t &longueur) {
    for (size_t i = 0; i < longueur; i++) {
        size_t longueurTemporaire = longueur - (i + 1);
        supprimerValeur(tableau + i + 1, longueurTemporaire, tableau[i]);
        longueur = longueurTemporaire + (i + 1);
    }
}


void afficherTableau(const int tableau[], size_t longueur) {
    cout << "[";
    for (size_t i = 0; i < longueur; ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << tableau[i];
    }
    cout << "]" << endl;
}

int main() {
    int t1[] = {0, 9, 2, 5, 5, 5, 6, 6, 8, 9};
    size_t t1_length = sizeof(t1) / sizeof(t1[0]);

    supprimerDoublons(t1, t1_length);
    cout << "t1: ";
    afficherTableau(t1, t1_length);
}