//---------------------------------------------------------
// Demo           : example
// Classe         : PRG1_E
// Fichier        : example.cpp
// Auteur(s)      : ValentinRicard
// But            : Fichier d'exemple
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <array>
#include <iostream>

using namespace std;

typedef array<int, 3> TestArray;

std::ostream &operator<<(std::ostream &os, const TestArray &value) {
    os << "[";
    for (size_t i = 0; i < value.size(); ++i) {
        if (i)
            os << ", ";
        os << value[i];
    }
    os << "]";
    return os;
}
int main() {
    TestArray array = {1, 2, 3};
    cout << array << endl;
    cout << "First: " << *array.begin() << ", last: " << *(array.end() - 1) << endl;

    array.fill(0);
    cout << array;
}