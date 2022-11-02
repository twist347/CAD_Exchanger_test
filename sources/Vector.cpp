#include "../headers/Vector.h"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Vector &v) {
    std::stringstream ss;
    ss << '{' << v.x << ',' << v.y << ',' << v.z << '}';
    os << ss.str();
    return os;
}

