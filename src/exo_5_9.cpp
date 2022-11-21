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

void supprimerElementCentral(int tableau[], size_t &longueur) {
    size_t milieu = (longueur - 1) / 2;
    supprimerElement(tableau, longueur, milieu);

    if (longueur % 2 == 1) {
        supprimerElement(tableau, longueur, milieu);
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
    int t1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t t1_length = sizeof(t1) / sizeof(t1[0]);

    supprimerElementCentral(t1, t1_length);
    cout << "t1: ";
    afficherTableau(t1, t1_length);
}