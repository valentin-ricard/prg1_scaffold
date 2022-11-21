//---------------------------------------------------------
// Demo           : exo_4_3
// Classe         : PRG1_E
// Fichier        : exo_4_3.cpp
// Auteur(s)      : ValentinRicard
// But            : Exercice 4.3
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

void printAllBetween(unsigned char boundary1, unsigned char boundary2) {
    for (unsigned char i = boundary1; i <= boundary2; i ++) {
        cout << i;
    }
}

int main() {
    printAllBetween('d', 'a');
}
