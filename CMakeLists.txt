cmake_minimum_required(VERSION 3.23)
project(test_for_CAD)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_for_CAD main.cpp headers/Circle.h headers/Ellipse.h headers/Helix.h headers/Point.h sources/Circle.cpp sources/Point.cpp sources/Ellipse.cpp headers/Curve.h sources/Helix.cpp headers/Vector.h sources/Vector.cpp)
