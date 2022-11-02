#include <cmath>

#include "../headers/Ellipse.h"

Point Ellipse::getPoint(double t) const {
    double x = radius * cos(t);
    double y = smallRadius * sin(t);
    return {x, y, 0};
}

Vector Ellipse::getDerivative(double t) const {
    double dx = -radius * sin(t);
    double dy = smallRadius * cos(t);
    return {dx, dy, 0};
}

