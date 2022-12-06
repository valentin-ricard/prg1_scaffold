//
// Created by ValentinRicard on 29.11.2022.
//

#include <iostream>
#include <sstream>

using namespace std;


int main() {
    int input;
    cout << "Entrez un nombre entier >= 0 :";
    cin >> input;
    // We need to find the first number
    stringstream s;
    s << input;


    // Do the thing
    cout << "Nombre saisi : " << input << endl
         << "Nombre de chiffres : " << s.str().length() << endl
         << "1er chiffre : " << s.str().at(0) << endl
         << "Dernier chiffre : " << s.str().at(s.str().length() - 1);
}