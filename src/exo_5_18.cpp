//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

typedef vector<int> Line;
typedef vector<Line> Matrice;

ostream &operator<<(ostream &os, const Line &v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

ostream &operator<<(ostream &os, const Matrice &m) {
    os << "[" << endl;
    for (const Line &ligne: m) {
        os << "  " << ligne << endl;
    }
    os << "]";

    return os;
}

int left_diag(const Matrice &mat) {
    size_t size = mat.size();
    int accum = 0;

    for (size_t i = 0; i < size; i++) {
        accum += mat[i].at(i);
    }

    return accum;
}
int right_diag(const Matrice &mat) {
    size_t size = mat.size();
    int accum = 0;

    for (size_t i = 0; i < size; i++) {
        accum += mat[i].at(size - i - 1);
    }

    return accum;
}


int main() {
    Matrice matrice = Matrice({{1, 0, 1}, {0, 1, 0}, {1, 1, 0}});

    cout << "Mat: " << matrice << endl
         << "Left: " << left_diag(matrice) << endl
         << "Right: " << right_diag(matrice) << endl;
}