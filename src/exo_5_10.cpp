//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>


using namespace std;

bool estCroissant(const int tableau[], size_t length) {
    for (size_t i = 1; i < length; ++i) {
        if (tableau[i-1] > tableau[i])
            return false;
    }
    return true;
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
         << "t1: " << estCroissant(t1, t1_length)
         << ", t2: " << estCroissant(t2, t2_length);

}