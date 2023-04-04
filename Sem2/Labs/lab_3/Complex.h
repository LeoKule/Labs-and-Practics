#ifndef LAB_3_COMPLEX_H
#define LAB_3_COMPLEX_H
#include <iostream>

class Complex {
private:
    double real, imaginary;

public:
    // Базовый конструктор
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    // Конструктор копирования
    Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}

    // Оператор присваивания копированием
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }

    // Деструктор
    ~Complex() {}

    // Оператор +=
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }

    // Оператор +
    friend Complex operator+(const Complex& lhs, const Complex& rhs) {
        return Complex(lhs.real + rhs.real, lhs.imaginary + rhs.imaginary);
    }

    // Оператор *=
    Complex& operator*=(const Complex& other) {
        double r = real * other.real - imaginary * other.imaginary;
        double i = real * other.imaginary + imaginary * other.real;
        real = r;
        imaginary = i;
        return *this;
    }

    // Оператор *
    friend Complex operator*(const Complex& lhs, const Complex& rhs) {
        return Complex(lhs.real * rhs.real - lhs.imaginary * rhs.imaginary,
                       lhs.real * rhs.imaginary + lhs.imaginary * rhs.real);
    }

    // Оператор ++ префиксный
    Complex& operator++() {
        ++real;
        return *this;
    }

    // Оператор ++ постфиксный
    Complex operator++(int) {
        Complex temp(*this);
        ++real;
        return temp;
    }

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Complex& obj) {
        is >> obj.real >> obj.imaginary;
        return is;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& obj) {
        os << obj.real << " + " << obj.imaginary << "i";
        return os;
    }
};

#endif //LAB_3_COMPLEX_H
