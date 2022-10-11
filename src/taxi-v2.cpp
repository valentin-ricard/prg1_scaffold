//---------------------------------------------------------
// Fichier        : LaboTaxi.cpp
// Auteur(s)      : Philibert Alexandre, Villegas Castrillon Adrian
// Date           : 2021-10-02
// But            : Un programme qui calcule le prix d'une course en € en taxi
// Modifications  :
// Remarque(s)    : Le programme ne gère pas les saisies
//---------------------------------------------------------

#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>  // cin et cout
#include <iomanip>   // setprecision
#include <limits>    // numeric_limits<streamsize>

using namespace std;

int main() {
    const float PRISE_EN_CHARGE = 5.00;
    const float SUPPLEMENT_PAR_BAGAGE = 2.50;
    const float TARIF_PAR_MINUTE = 1.20;

    int   nombreBagages; // Il n'est pas possible d'avoir 1/2 bagage, ils sont représentés par un entier
    float distanceKm;
    float vitesseKmH;
    float prixCourse;
    float supplementBagages;

    // définit la précision d'affichage des nombres à virgules (exemple: 2.50)
    cout << fixed << setprecision(2);

    cout << "bonjour, ce programme calcule le prix d'une course en € en taxi voici les conditions" << endl
         << "====================================================================================" << endl
         << " - prise en charge : " << PRISE_EN_CHARGE                                             << endl
         << " - supp par bagage : " << SUPPLEMENT_PAR_BAGAGE                                       << endl
         << " - tarif/minute    : " << TARIF_PAR_MINUTE                                            << endl
         << endl;

    cout << "votre commande" << endl
         << "==============" << endl;

    cout << " - nbre de bagage : ";
    cin >> nombreBagages;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << " - distance [km]  : ";
    cin >> distanceKm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << " - vitesse [km/h] : ";
    cin >> vitesseKmH;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    supplementBagages = SUPPLEMENT_PAR_BAGAGE * nombreBagages;
    prixCourse = distanceKm / vitesseKmH * 60 * TARIF_PAR_MINUTE;

    cout << endl
         << "votre ticket"                                 << endl
         << "============"                                 << endl
         << " - prise en charge   : " << PRISE_EN_CHARGE   << endl
         << " - supp bagages      : " << supplementBagages << endl
         << " - prix de la course : " << prixCourse        << endl
         << endl
         << "TOTAL : " << PRISE_EN_CHARGE + supplementBagages + prixCourse
         << endl
         << endl;

    cout << "presser ENTER pour quitter";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

    return EXIT_SUCCESS;
}