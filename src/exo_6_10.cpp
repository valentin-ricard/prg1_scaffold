//
// Created by ValentinRicard on 29.11.2022.
//

#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    string nom, prenom;
    cin >> prenom >> nom;
    cout << "Prenom: " << prenom << endl
         << "Nom: " << nom << endl
         // TODO: Fixer l'affichage en string.
         << "Acronmye: " << ""s.append(1, (char) toupper(prenom.at(0)))
            .append(1, (char) toupper(nom.at(0))).append(1, (char) toupper(*(nom.end() -1)));
}