#include <cmath>

#include "../headers/Helix.h"

Point Helix::getPoint(double t) const {
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = step * t;
    return {x, y, z};
}

Vector Helix::getDerivative(double t) const {
    double dx = -radius * sin(t);
    double dy = radius * cos(t);
    double dz = step;
    return {dx, dy, dz};
}

