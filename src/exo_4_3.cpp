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

double getAreaOfRectangle(double length, double width);
double getVolumeOfPyramid(double baseArea, double height);
double getVolumeOfRectangularPyramid(double length, double width, double height);

int main() {
    double longueur, largeur, hauteur;
    cout << "Longeur: ";
    cin >> longueur;
    cout << "Largeur: ";
    cin >> largeur;
    cout << "Hauteur: ";
    cin >> hauteur;

    // Let's use the formula
    cout << "Résultat: " << fixed << setprecision(1) << getVolumeOfRectangularPyramid(longueur, largeur, hauteur) << endl;
}

double getAreaOfRectangle(double length, double width) {
    return width * length;
}

double getVolumeOfPyramid(double baseArea, double height) {
    return (baseArea * height) / 3.0;
}

double getVolumeOfRectangularPyramid(double length, double width, double height) {
    return getVolumeOfPyramid(getAreaOfRectangle(length, width), height);
}

