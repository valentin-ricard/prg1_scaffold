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
#include <vector>

using namespace std;

enum class MedalType {
    GOLD = 0,
    SILVER = 1,
    BRONZE = 2
};

typedef array<int, 3> MedalsArray;
typedef vector<MedalsArray> MedalsTable;

std::ostream &operator<<(std::ostream &os, const MedalsArray &value) {
    os << "[";
    for (size_t i = 0; i < value.size(); ++i) {
        if (i)
            os << ", ";
        os << value[i];
    }
    os << "]";
    return os;
}

int getCount(const MedalsArray &value, MedalType type) {
    return value[(size_t) type];
}

int medalsOfCountry(const MedalsArray &value) {
    return getCount(value, MedalType::GOLD) + getCount(value, MedalType::SILVER) + getCount(value, MedalType::BRONZE);
}

int totalMedalCount(const MedalsTable &value, MedalType type) {
    int result = 0;

    for (const MedalsArray &country: value) {
        result += getCount(country, type);
    }

    return result;
}

int main() {
    MedalsTable table = {
            {1,0,1},
            {1,1,0},
            {0,0,1},
            {1,0,0},
            {0,1,1},
            {0,1,1},
            {1,1,0},
    };

    cout << "Médailles Chine : " << medalsOfCountry(table[1]) << endl
         << "Total or        : " << totalMedalCount(table, MedalType::GOLD) << endl;
}