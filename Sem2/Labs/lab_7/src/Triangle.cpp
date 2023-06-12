#include "Triangle.h"

Triangle::Triangle(double x, double y, const std::string& color, double base, double height)
        : Shape(x, y, color), base(base), height(height) {}

double Triangle::getArea() const {
    return 0.5 * base * height;
}
