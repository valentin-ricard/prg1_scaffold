//---------------------------------------------------------
// Demo           : exo_3_26
// Classe         : PRG1_E
// Fichier        : exo_3_26.cpp
// Auteur(s)      : ValentinRicard
// But            : Exercice 3.26
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int h;
    do {
        cout << "Hauteur du triangle (h >= 0)";
        cin >> h;
    } while (h < 0);

    for (int i = 0; i < h; ++i) {
        // First show spaces
        for (int j = 0; j < h - i - 1; ++j) {
            cout << " ";
        }
        // Then show stars
        for (int j = 0; j < i * 2 + 1; ++j) {
            cout << "*";
        }
        //Start a new line
        cout << endl;
    }
}