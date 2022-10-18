enum class Mois {
    JANVIER,
    FEVRIER,
    MARS,
    AVRIL,
    MAI,
    JUIN,
    JUILLET,
    AOUT,
    SEPTEMBRE,
    OCTOBRE,
    NOVEMBRE,
    DECEMBRE
};

#include <iostream>

using namespace std;

int main() {
    cout << "Entrez un mois [1-12]: ";
    int noMois;
    cin >> noMois;

    cout << "Ce mois contient ";
    switch ((Mois) (noMois - 1)) {
        case Mois::JANVIER:
        case Mois::MARS:
        case Mois::MAI:
        case Mois::JUILLET:
        case Mois::AOUT:
        case Mois::OCTOBRE:
        case Mois::DECEMBRE:
            cout << "31";
            break;
        case Mois::FEVRIER:
            cout << "28 ou 29";
            break;
        default:
            cout << "30";
    }
    cout << " jours.";

    return 0;
}