#include "coordinate.h"

Coordinate::Coordinate(int x, int y) : x{x}, y{y} {}

int Coordinate::getX() {
    return this->x;
}

int Coordinate::getY() {
    return this->y;
}