#include <iostream>
#include "Complex.h"

int main() {
    setlocale(LC_ALL, "ru");
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c5(c1); // Создание копии комплексного числа с1

    // Операторы +=
    c1 += c2;
    std::cout << c1 << std::endl;  // Выводит "4 + 6i"

    // Оператор +
    Complex c3 = c1 + c2;
    std::cout << c3 << std::endl;  // Выводит "7 + 10i"

    // Оператор *=
    c1 *= c2;
    std::cout << c1 << std::endl;  // Выводит "-5 + 10i"

    // Оператор *
    Complex c4 = c2 * c3;
    std::cout << c4 << std::endl;  // Выводит "-32 + 70i

    ++c1; // Увеличение действительной части на 1, результат сохранится в c1
    Complex с6 = c1++; // Увеличение действительной части на 1, но результат сохранится в c2

    // Операторы ввода и вывода :
    Complex z;
    std::cout << "Введите комплексное число:" << std::endl;
    std::cin >> z;
    std::cout << z + 1;
    system("pause");
}