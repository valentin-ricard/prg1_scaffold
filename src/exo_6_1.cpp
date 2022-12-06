//
// Created by ValentinRicard on 29.11.2022.
//

#include <iostream>
#include <cctype>

using namespace std;

void display_test(char c, const string& message, bool result) {
    cout << "'" << c << "' est " << message << ": " << (result ? "vrai" : "faux");
}

int main() {
    cout << "Entrer un caractère: ";
    char c;
    cin >> c;
    display_test(c, "une lettre de l'alphabet", isalpha(c));
    display_test(c, "une lettre minuscule", islower(c));
    display_test(c, "un chiffre", isdigit(c));
    display_test(c, "un caractere de ponctuation", ispunct(c));
}