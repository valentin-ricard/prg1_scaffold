//
// Created by ValentinRicard on 06.12.2022.
//

#ifndef PRG_HEIG_POINT_H
#define PRG_HEIG_POINT_H

class Point {
    float x;
    float y;
public:
    Point(float x, float y);

    void deplacer(float moveX, float moveY);

    void afficher() const;
};


#endif //PRG_HEIG_POINT_H
