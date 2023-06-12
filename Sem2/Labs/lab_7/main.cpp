#include <iostream>
#include <vector>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Triangle(0, 0, "Red", 5, 4));
    shapes.push_back(new Rectangle(0, 0, "Blue", 6, 3));
    shapes.push_back(new Circle(0, 0, "Green", 2.5));

    for (const auto& shape : shapes) {
        shape->printArea();
    }

    // Освобождение памяти
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}