#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <algorithm>
#include "headers/Curve.h"
#include "headers/Circle.h"
#include "headers/Ellipse.h"
#include "headers/Helix.h"

void populateFirstVector(std::vector<std::shared_ptr<Curve>> &curves, int n, int &numberOfCircles);

void
populateSecondVector(const std::vector<std::shared_ptr<Curve>> &curves, std::vector<std::shared_ptr<Curve>> &circles);

void sortSecondVectorByRadius(std::vector<std::shared_ptr<Curve>> &circles);

double calculateSumOfRadii(const std::vector<std::shared_ptr<Curve>> &circles);

int main() {
    int n = 100;
    std::vector<std::shared_ptr<Curve>> curves;
    curves.reserve(n);

    // For reserve vector of circles
    int numberOfCircles = 0;

    populateFirstVector(curves, n, numberOfCircles);

    std::vector<std::shared_ptr<Curve>> circles;
    circles.reserve(numberOfCircles);

    populateSecondVector(curves, circles);

    sortSecondVectorByRadius(circles);

    auto sum = calculateSumOfRadii(circles);

    std::cout << "Sum of radii of all circles: " << sum << '\n';
}

void populateFirstVector(std::vector<std::shared_ptr<Curve>> &curves, int n, int &numberOfCircles) {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 3);
    std::uniform_int_distribution<std::mt19937::result_type> radius(1, 100);
    std::uniform_int_distribution<std::mt19937::result_type> a(1, 100);
    std::uniform_int_distribution<std::mt19937::result_type> b(1, 100);

    for (int i = 0; i < n; ++i) {
        auto val = dist(gen);
        if (val == 1) {
            curves.push_back(std::make_shared<Circle>(radius(gen)));
            ++numberOfCircles;
            std::cout << i + 1 << ": Circle: ";
        } else if (val == 2) {
            curves.push_back(std::make_shared<Ellipse>(a(gen), b(gen)));
            std::cout << i + 1 << ": Ellipse: ";
        } else {
            curves.push_back(std::make_shared<Helix>(a(gen), b(gen)));
            std::cout << i + 1 << ": Helix: ";
        }
        std::cout << "point value = " << curves[i]->getPoint(M_PI_4) << ", derivative = "
                  << curves[i]->getDerivative(M_PI_4) << '\n';
    }
}

void
populateSecondVector(const std::vector<std::shared_ptr<Curve>> &curves, std::vector<std::shared_ptr<Curve>> &circles) {
    std::copy_if(curves.begin(), curves.end(), std::back_inserter(circles),
                 [](const auto &curve) { return dynamic_cast<Circle *>(curve.get()); });
}

void sortSecondVectorByRadius(std::vector<std::shared_ptr<Curve>> &circles) {
    std::sort(circles.begin(), circles.end(),
              [](const auto &lhs, const auto &rhs) {
                  return lhs->radius < rhs->radius;
              });
}

double calculateSumOfRadii(const std::vector<std::shared_ptr<Curve>> &circles) {
    double sum = 0;
    std::for_each(circles.begin(), circles.end(),
                  [&sum](const auto &circle) { sum += circle->radius; });
    return sum;
}