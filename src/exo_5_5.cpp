//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

size_t lire_valeurs(double valeurs[], size_t maxLength) {
    cout << "Entrez la liste de vos notes (" << maxLength << " notes max), 0 pour quitter:" << endl;
    double tempValue;
    for (size_t i = 0; i < maxLength; ++i) {
        cin >> tempValue;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();
        if (tempValue != 0) {
            valeurs[i] = tempValue;
        } else {
            return i;
        }
    }
    return maxLength;
}

double moyenne(const double valeurs[], size_t longueur) {
    assert(longueur != 0);

    double total = 0;
    for (size_t i = 0; i < longueur; ++i) {
        total += valeurs[i];
    }
    return total / static_cast<double>(longueur);
}

int main() {
    const size_t LONGUEUR = 10;
    double tableau[LONGUEUR];

    size_t longueurUtile = lire_valeurs(tableau, LONGUEUR);
    if (longueurUtile != 0) {
        cout << "La moyenne des notes saisies = " << setprecision(3) << moyenne(tableau, longueurUtile);
    } else {
        cout << "Moyenne non calculable car aucune note saisie !";
    }
}