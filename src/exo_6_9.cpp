//
// Created by ValentinRicard on 29.11.2022.
//

#include <iostream>

using namespace std;


int main() {
    string input;
    cout << "Entrez un nombre entier >= 0 :";
    cin >> input;

    // Do the thing
    cout << "Nombre saisi : " << input << endl
         << "Nombre de chiffres : " << input.length() << endl
         << "1er chiffre : " << *input.begin() << endl
         << "Dernier chiffre : " << *(input.end() - 1);
}