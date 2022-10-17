//---------------------------------------------------------
// Demo           : exo_3_20
// Classe         : PRG1_E
// Fichier        : exo_3_20.cpp
// Auteur(s)      : ValentinRicard
// But            : Exercice 3.20
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int i = 20;
    while (i > 0) {
        cout << setw(2) << i << " ";
        if (i % 3 == 0) {
            cout << endl;
        }
        i--;
    }
}