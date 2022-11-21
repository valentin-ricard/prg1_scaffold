//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>


using namespace std;

void decalerDroite(int tableau[], size_t length) {
    if (length == 0)
        return;

    int dernier = tableau[length - 1];
    for (size_t i = length - 1; i > 0; --i) {
        tableau[i] = tableau[i-1];
    }

    tableau[0] = dernier;
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

    decalerDroite(t1, t1_length);
    cout << "t1: ";
    afficherTableau(t1, t1_length);
}