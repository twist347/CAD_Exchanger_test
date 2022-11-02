#include "../headers/Point.h"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Point &point) {
    std::stringstream ss;
    ss << '(' << point.x << ',' << point.y << ',' << point.z << ')';
    os << ss.str();
    return os;
}

