//
// Created by ValentinRicard on 29.11.2022.
//

#include <iostream>

using namespace std;

string milieu(const string &entree) {
    if (entree.length() % 2 == 0) {
        return entree.substr((entree.length() / 2) - 1, 2);
    } else {
        return entree.substr(entree.length() / 2, 1);
    }
}

int main() {
    cout << milieu("1234") << "/" << milieu("123");
}