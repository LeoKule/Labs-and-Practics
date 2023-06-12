#include "Shape.h"
#include <iostream>

Shape::Shape(double x, double y, const std::string& color) : x(x), y(y), color(color) {}

void Shape::printArea() const {
    std::cout << "Area: " << getArea() << std::endl;
}
