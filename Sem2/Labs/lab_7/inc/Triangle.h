#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.h"

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double x, double y, const std::string& color, double base, double height);

    [[nodiscard]] double getArea() const override;
};

#endif  // TRIANGLE_HPP
