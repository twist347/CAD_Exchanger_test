#ifndef TEST_FOR_CAD_POINT_H
#define TEST_FOR_CAD_POINT_H

#include <ostream>

class Point {
private:
    double x;
    double y;
    double z;
public:

    Point(double x, double y, double z) : x(x), y(y), z(z) {

    }

    friend std::ostream &operator<<(std::ostream &os, const Point &point);
};

#endif //TEST_FOR_CAD_POINT_H
