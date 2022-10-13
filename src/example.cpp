//---------------------------------------------------------
// Demo           : example
// Classe         : PRG1_E
// Fichier        : example.cpp
// Auteur(s)      : ValentinRicard
// But            : Fichier d'exemple
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>

using namespace std;

int main() {
    int a, b, c, tmp;
    cin >> a >> b >> c;

    while (!(a <= b && b <= c)) {
        if (a > b) {
            tmp = b;
            b = a;
            a = tmp;
        }

        if (b > c) {
            tmp = c;
            c = b;
            b = tmp;
        }
    }

    cout << a << " " << b << " " << c;
}