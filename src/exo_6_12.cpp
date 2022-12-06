//
// Created by ValentinRicard on 29.11.2022.
//

#include <iomanip>
#include <iostream>

using namespace std;


int main() {
    string contenu = "aabacbabcdabcdeabcdefabcdefg";
    cout << "Contenu: " << contenu;
    char cherche;
    cin >> cherche;
    int compte1 = 0;
    size_t lastIndex = 0;
    while ((lastIndex = contenu.find(cherche, lastIndex)) != string::npos) {
        ++lastIndex;
        ++compte1;
    }


    cout << "Compte: " << compte1 << ", " << std::count_if(contenu.begin(), contenu.end(), [&](const auto &item) {
        return item == cherche;
    });
}