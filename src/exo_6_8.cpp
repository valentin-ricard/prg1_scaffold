//
// Created by ValentinRicard on 29.11.2022.
//

#include <cassert>
#include <iostream>

using namespace std;

int ordre(char caractere) {
    switch (caractere) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int convertirRomain(const string &entree) {
    int accum = 0;
    int result = 0;
    for (auto iter = entree.begin(); iter != entree.end(); ++iter) {
        // Le dernier caractère est toujours ajouté:
        if (iter == entree.end() - 1 || ordre(*iter) >= ordre(*(iter + 1))) {
            // Sinon on l'ajoute au résultat (en prenant en compte l'accumulateur
            result += (ordre(*iter) - accum);
            accum = 0;
        } else {
            // Si le caractère d'après est plus grand, on l'ajoute à l'accumulateur
            accum += ordre(*iter);
        }
    }

    return result;
}

int main() {
    assert(convertirRomain("XIV") == 14);
    assert(convertirRomain("MXX") == 1020);
}