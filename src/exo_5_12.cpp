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


void afficherTableau(const int tableau[], size_t length) {
    cout << "[";
    for (size_t i = 0; i < length; ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << tableau[i];
    }
    cout << "]" << endl;
}

int main() {
    int t1[] = {0, 1, 2, 5, 5, 5, 6, 7, 8, 9};
    size_t t1_length = sizeof(t1) / sizeof(t1[0]);

    supprimerValeur(t1, t1_length, 5);
    cout << "t1: ";
    afficherTableau(t1, t1_length);
}