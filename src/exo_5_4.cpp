//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>

using namespace std;

void afficherTableau(const int tableau[], size_t length) {
    cout << "[";
    for (size_t i = 0; i < length; ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << tableau[i];
    }
    cout << "]" << endl;
}

int main() {
    afficherTableau({}, 0);
    int t1[] = {1};
    afficherTableau(t1, 1);
    int t2[] = {1,2};
    afficherTableau(t2, 2);
}