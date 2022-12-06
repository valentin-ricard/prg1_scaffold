//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

ostream &operator<<(ostream &os, const vector<string> &values) {
    os << "[" << endl;
    for (const string &ligne: values) {
        os << "  " << ligne << endl;
    }
    os << "]";

    return os;
}

vector<string> getCharMatrix() {
    vector<string> result;
    for (char i = 'z'; i >= 'a'; --i) {
        string value;

        for (char y = 'a'; y <= i; ++y) {
            value += y;
        }
        result.push_back(value);
    }
    return result;
}


int main() {
    cout << getCharMatrix();
}