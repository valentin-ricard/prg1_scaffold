//
// Created by ValentinRicard on 06.12.2022.
//

#include "Point.h"

#include <iostream>

Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
}

void Point::deplacer(float moveX, float moveY) {
    this->x += moveX;
    this->y += moveY;
}

void Point::afficher() const {
    std::cout << "(" << x << ", " << y << ")";
}

