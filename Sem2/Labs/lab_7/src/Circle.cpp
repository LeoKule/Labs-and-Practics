#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>

Circle::Circle(double x, double y, const std::string& color, double radius)
        : Shape(x, y, color), radius(radius) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}
