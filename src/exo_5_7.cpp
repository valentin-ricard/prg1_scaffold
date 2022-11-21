//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

void remplacerValeursPaires(int tableau[], size_t longueur, int remplacement) {
    for (size_t i = 0; i < longueur; ++i) {
        if (tableau[i] % 2 == 0) {
            tableau[i] = remplacement;
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
    int t1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t t1_length = sizeof(t1) / sizeof(t1[0]);

    remplacerValeursPaires(t1, t1_length, 0);
    cout << "t1: ";
    afficherTableau(t1, t1_length);
}