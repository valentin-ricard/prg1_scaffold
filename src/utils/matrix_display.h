//
// Created by ValentinRicard on 21.11.2022.
//

#ifndef PRG_HEIG_MATRIX_DISPLAY_H
#define PRG_HEIG_MATRIX_DISPLAY_H

#include <vector>
#include <ostream>

typedef std::vector<int> Line;
typedef std::vector<Line> Matrice;

std::ostream &operator<<(std::ostream &os, const Line &v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Matrice &m) {
    os << "[" << std::endl;
    for (const Line &ligne: m) {
        os << "  " << ligne << std::endl;
    }
    os << "]";

    return os;
}



#endif//PRG_HEIG_MATRIX_DISPLAY_H
