//---------------------------------------------------------
// Demo           : exo_3_24
// Classe         : PRG1_E
// Fichier        : exo_3_24.cpp
// Auteur(s)      : ValentinRicard
// But            : Exercice 3.24
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#define CLEAR_BUF cin.ignore(numeric_limits<streamsize>::max(), '\n')

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double G = 9.81;

int main() {

    double epsilon;
    do {
        cout << "Coef. de rebond: ";
        cin >> epsilon;
        CLEAR_BUF;
    } while (not (0 <= epsilon && epsilon < 1));


    double h_0;
    do {
        cout << "Hauteur initiale: ";
        cin >> h_0;
        CLEAR_BUF;
    } while (h_0 < 0);


    int rebonds;
    do {
        cout << "Nombre de rebonds: ";
        cin >> rebonds;
        CLEAR_BUF;
    } while (rebonds < 0);

    double height = h_0;
    for (int i = 0; i < rebonds; ++i) {
        double speed = sqrt(2.0 * G * height) * epsilon;
        height = pow(speed, 2) / (2.0*G);
    }

    cout << "Hauteur après " << setw(4) << rebonds << " rebonds: " << setprecision(2) << height;
}