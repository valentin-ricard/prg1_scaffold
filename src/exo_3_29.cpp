//---------------------------------------------------------
// Demo           : exo_3_29
// Classe         : PRG1_E
// Fichier        : exo_3_29.cpp
// Auteur(s)      : ValentinRicard
// But            : PPMC
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int m;
    do {
        cout << "m: ";
        cin >> m;
        if (m <= 0) {
            cout << "Erreur. La valeur saisie doit être > 0" << endl;
        }
    } while (m <= 0);

    int n;
    do {
        cout << "n: ";
        cin >> n;
        if (n <= 0) {
            cout << "Erreur. La valeur saisie doit être > 0" << endl;
        }
    } while (n <= 0);

    int ppcm = 2;
    while (not(ppcm % m == 0 && ppcm % n == 0)) {
        ppcm++;
    }

    cout << "Le PPCM est " << ppcm;
}