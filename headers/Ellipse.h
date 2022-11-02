#ifndef TEST_FOR_CAD_ELLIPSE_H
#define TEST_FOR_CAD_ELLIPSE_H

#include "Curve.h"

class Ellipse : public Curve {
private:
    double smallRadius;

public:
    Ellipse(double a, double b) : Curve(a), smallRadius(b) {

    }

    Point getPoint(double t) const override;

    Vector getDerivative(double t) const override;
};

#endif //TEST_FOR_CAD_ELLIPSE_H
