#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

class Shape {
protected:
    double x, y; // координаты
    std::string color; // цвет

public:
    Shape(double x, double y, const std::string& color);

    [[nodiscard]] virtual double getArea() const = 0; // виртуальный метод для вычисления площади

    virtual void printArea() const;
};

#endif  // SHAPE_HPP
