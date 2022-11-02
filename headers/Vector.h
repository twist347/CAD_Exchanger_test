#ifndef TEST_FOR_CAD_VECTOR_H
#define TEST_FOR_CAD_VECTOR_H

#include <ostream>

class Vector {
private:
    double x;
    double y;
    double z;

public:
    Vector(double x, double y, double z) : x(x), y(y), z(z) {

    }

    friend std::ostream &operator<<(std::ostream &os, const Vector &v);
};

#endif //TEST_FOR_CAD_VECTOR_H
