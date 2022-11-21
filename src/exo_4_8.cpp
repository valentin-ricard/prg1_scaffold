//---------------------------------------------------------
// Demo           : exo_4_8
// Classe         : PRG1_E
// Fichier        : exo_4_8.cpp
// Auteur(s)      : ValentinRicard
// But            : Exercice 4.8, Permutation circulaire droite
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>

bool operation(double a, double b, char operateur);

int main() {
    double a = 1.0, b = 2.0, c = 3.0;
    std::cout << "Before => " << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    operation(a, b, c);
    std::cout << "After => " << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
}

bool operation(double a, double b, char operateur) {
    std::swap(a, operateur);
    std::swap(b, operateur);
}

