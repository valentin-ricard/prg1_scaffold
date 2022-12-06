//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>
#include <vector>

#include "utils/matrix_display.h"
#include "utils/saisie.h"

using namespace std;


Matrice getMagicCube(int order) {
    size_t orderSize = (size_t) order;

    Matrice result = Matrice(orderSize, Line(orderSize, 0));
    size_t lineNb = orderSize - 1,
        columnNb = orderSize / 2;

    for (size_t k = 1; k <= orderSize * orderSize; ++k) {
        result[lineNb][columnNb] = (int) k;
        size_t tempLineNb = (lineNb + 1) % orderSize,
            tempColumnNb = (columnNb + 1) % orderSize;

        if (result[tempLineNb][tempColumnNb] != 0) {
            // Do not change the values, instead just decrement the column
            --lineNb;
        } else {
            lineNb = tempLineNb;
            columnNb = tempColumnNb;
        }
    }
    return result;
}


int main() {
    int order = getInt("Entrez l'ordre du carre magique souhaite (entier impair > 0)",
                       "Saisie incorrecte. Veuillez SVP recommencer.",
                       0, numeric_limits<int>::max(), [](int value) { return value % 2 == 1; });

    cout << getMagicCube(order);
}