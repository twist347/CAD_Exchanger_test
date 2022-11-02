#ifndef TEST_FOR_CAD_HELIX_H
#define TEST_FOR_CAD_HELIX_H

#include "Curve.h"

class Helix : public Curve {
private:
    double step;

public:
    Helix(double radius, double step) : Curve(radius), step(step) {

    }

    Point getPoint(double t) const override;

    Vector getDerivative(double t) const override;

};

#endif //TEST_FOR_CAD_HELIX_H
