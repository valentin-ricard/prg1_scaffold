//---------------------------------------------------------
// Demo           : 2022-09-22_PremierCode
// Fichier        : 2022-09-22_PremierCode.cpp
// Auteur(s)      : BREGUET Guy-Michel
// But            : premier programme en C++
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

int main() {
    cout << "Bienvenue en PRG1" << endl;
    cout << numeric_limits<unsigned long long>::lowest() << " -> " << log2(numeric_limits<unsigned long long>::max())/8;
    return 0;
}
