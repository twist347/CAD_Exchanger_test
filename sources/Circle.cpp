#include <cmath>

#include "../headers/Circle.h"

Point Circle::getPoint(double t) const {
    double x = radius * cos(t);
    double y = radius * sin(t);
    return {x, y, 0};
}

Vector Circle::getDerivative(double t) const {
    double dx = -radius * sin(t);
    double dy = radius * cos(t);
    return {dx, dy, 0};
}
