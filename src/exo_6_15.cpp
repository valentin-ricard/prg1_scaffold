//
// Created by ValentinRicard on 29.11.2022.
//

#include <iostream>
#include <iomanip>

using namespace std;

string saison(int mois, int jour) {
    if (mois < 3 || (mois == 3 && jour >= 21)) {
        return "Hiver";
    } else if (mois < 6 || (mois == 6 && jour >= 21)) {
        return "Printemps";
    } else if (mois < 9 || (mois == 9 && jour >= 21)) {
        return "Ete";
    } else if (mois < 12 || (mois == 12 && jour >= 21)) {
        return "Automne";
    } else {
        return "Hiver";
    }
}

int main() {
    string buf;
    getline(cin, buf);
    stringstream s;
    s.str(buf);

    int jour, mois;
    s >> mois;
    s.ignore();
    s >> jour;

    cout << "Saison: " << saison(mois, jour);
}