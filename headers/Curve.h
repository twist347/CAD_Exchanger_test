#ifndef TEST_FOR_CAD_CURVE_H
#define TEST_FOR_CAD_CURVE_H

#include "Point.h"
#include "Vector.h"

class Curve {

public:
    double radius;

    virtual Point getPoint(double t) const = 0;

    virtual Vector getDerivative(double t) const = 0;

    explicit Curve(double radius) : radius(radius) {}

    virtual ~Curve() = default;
};

#endif //TEST_FOR_CAD_CURVE_H
