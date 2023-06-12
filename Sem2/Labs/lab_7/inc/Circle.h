#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double x, double y, const std::string& color, double radius);

    [[nodiscard]] double getArea() const override;
};

#endif  // CIRCLE_HPP
