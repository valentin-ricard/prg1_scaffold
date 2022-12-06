//
// Created by ValentinRicard on 08.11.2022.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool nombreEstImpair(int nombre) {
    return nombre % 2 == 1;
}

bool estImpair(const vector<int> &tableau) {
    return find_if_not(tableau.begin(), tableau.end(), nombreEstImpair) == tableau.end();
}

int main() {
    vector<int> tableau1 = {1, 3, 5, 7, 11};
    vector<int> tableau2 = {1, 3, 5, 7, 12};

    cout << boolalpha << "t1: " << estImpair(tableau1) << ", t2: " <<estImpair(tableau2);
}