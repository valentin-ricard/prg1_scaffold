//---------------------------------------------------------
// Demo           : exo_3_28
// Classe         : PRG1_E
// Fichier        : exo_3_28.cpp
// Auteur(s)      : ValentinRicard
// But            : Série harmonique
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int amount;
    do {
        cout << "Combien de termes voulez-vous ? ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Erreur. La valeur saisie doit être > 0" << endl;
        }
    } while (amount <= 0);

    double accumulator = 0.0;
    for (int k = 1; k <= amount; ++k) {
        accumulator += (1.0 / double(k));
    }

    cout << "La somme des " << amount << " premiers termes de la série vaut " << accumulator;
}