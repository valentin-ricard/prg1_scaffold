//
// Created by ValentinRicard on 29.11.2022.
//

#include <iostream>

using namespace std;

int main() {
    string s;
    s.append(3, ' ')
            .append(1, '*') += '\n';
    s.append(2, ' ')
            .append(3, '*') += '\n';
    s.append(1, ' ')
            .append(5, '*') += '\n';
    s.append(7, '*') += '\n';
    s.append(1, ' ')
            .append(5, '*') += '\n';
    s.append(2, ' ')
            .append(3, '*') += '\n';
    s.append(3, ' ')
            .append(1, '*') += '\n';

    cout << s;

}