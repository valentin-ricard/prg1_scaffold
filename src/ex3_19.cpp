//---------------------------------------------------------
// Demo           : ex3_19
// Classe         : PRG1_E
// Fichier        : ex3_19.cpp
// Auteur(s)      : ValentinRicard
// But            : Exercice 3.19 du cahier d'exercices
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    cout << "Montant: ";
    float amount;
    cin >> amount;

    cout << "Taux d'intéret annuel (en %): ";
    float interestRate;
    cin >> interestRate;


    int years = 0;
    float amountWithInterests = amount;
    float targetAmount = amount * 2;

    // Loop version
    while (amountWithInterests < targetAmount) {
        amountWithInterests *= 1.0f + (interestRate / 100);
        ++years;
    }
    cout << "Nombre d'années pour doubler (loop): " << years << endl;

    // Loopless version
    // The formula is the following: ln(2)/interestRate[0-1]
    years = ceil(0.6931471f / (interestRate / 100.0f));

    cout << "Nombre d'années pour doubler (fixed): " << years << endl;
}