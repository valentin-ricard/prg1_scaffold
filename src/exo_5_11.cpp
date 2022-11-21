//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>


using namespace std;

int sommeAlternee(const int tableau[], size_t length) {
    int accum = 0;
    for (size_t i = 0; i < length; ++i) {
        int signe = i % 2 ? -1 : 1;
        accum += (signe * tableau[i]);
    }

    return accum;
}

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
    int t1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t t1_length = sizeof(t1) / sizeof(t1[0]);

    int t2[] = {0, 1, 2, 3, 4, 6, 5, 7, 8, 9};
    size_t t2_length = sizeof(t2) / sizeof(t2[0]);

    cout << boolalpha
         << "t1: " << sommeAlternee(t1, t1_length)
         << ", t2: " << sommeAlternee(t2, t2_length);

}