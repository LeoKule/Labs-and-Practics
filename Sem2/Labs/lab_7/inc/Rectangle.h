#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double x, double y, const std::string& color, double width, double height);

    [[nodiscard]] double getArea() const override;
};

#endif  // RECTANGLE_HPP
