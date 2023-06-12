#include "Rectangle.h"

Rectangle::Rectangle(double x, double y, const std::string& color, double width, double height)
        : Shape(x, y, color), width(width), height(height) {}

double Rectangle::getArea() const {
    return width * height;
}
