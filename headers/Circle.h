#ifndef TEST_FOR_CAD_CIRCLE_H
#define TEST_FOR_CAD_CIRCLE_H

#include "Curve.h"

class Circle : public Curve {

public:
    explicit Circle(double radius) : Curve(radius) {

    }

    Point getPoint(double t) const override;

    Vector getDerivative(double t) const override;

    double getRadius() const {
        return radius;
    }
};

#endif //TEST_FOR_CAD_CIRCLE_H
