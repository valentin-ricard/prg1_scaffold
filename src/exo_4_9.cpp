//---------------------------------------------------------
// Demo           : exo_4_9
// Classe         : PRG1_E
// Fichier        : exo_4_9.cpp
// Auteur(s)      : ValentinRicard
// But            : Exercice 4.9, Retrait d'argent
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cmath> // std::min(...)

double retrait(double &soldeCourant, double const &montant);

int main() {
    double solde = 500.0;
    std::cout << std::fixed << std::setprecision(2) << "Solde initial du compte: " << solde << std::endl;
    std::cout << "Retrait 1, demandé 300, mais " << retrait(solde, 300.0) << " effectif." << std::endl;
    std::cout << "Solde du compte : " << solde << std::endl;
    std::cout << "Retrait 2, demandé 300, mais " << retrait(solde, 300.0) << " effectif." << std::endl;
    std::cout << "Solde du compte : " << solde << std::endl;
}

double retrait(double &soldeCourant, double const &montant) {
    if (soldeCourant <= 0) {
        std::cout << "Le solde ne peut pas être négatif!";
        return 0;
    }
    double montantEffectif = std::min(soldeCourant, montant);
    soldeCourant -= montantEffectif;

    return montantEffectif;
}

