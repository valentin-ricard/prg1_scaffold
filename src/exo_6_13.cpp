//
// Created by ValentinRicard on 29.11.2022.
//

#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;


int main() {
    string contenu;

    cout << "Addresse: ";
    getline(cin, contenu);
    stringstream stream;
    stream.str(contenu);
    string word,
            rue,
            numero;

    while (stream >> word) {
        if (isdigit(word.at(0))) {
            // Passer en addresse:
            numero += word;
        } else {
            if (!rue.empty()) {
                rue += " ";
            }
            rue += word;
        }
    }

    cout << "Rue: " << rue << endl
         << "Numero: " << numero << endl;
}