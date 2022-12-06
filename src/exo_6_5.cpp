//
// Created by ValentinRicard on 29.11.2022.
//

#include <iostream>

using namespace std;

int main() {
    string s;
    cout << boolalpha
        << (s == "") << endl
        << (s.empty()) << endl
        << (s.length() == 0) << endl
        << (s.begin() == s.end()) << endl;
}