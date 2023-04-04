#include <iostream>
#include "Complex.h"

int main() {
    setlocale(LC_ALL, "ru");
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c5(c1); // �������� ����� ������������ ����� �1

    // ��������� +=
    c1 += c2;
    std::cout << c1 << std::endl;  // ������� "4 + 6i"

    // �������� +
    Complex c3 = c1 + c2;
    std::cout << c3 << std::endl;  // ������� "7 + 10i"

    // �������� *=
    c1 *= c2;
    std::cout << c1 << std::endl;  // ������� "-5 + 10i"

    // �������� *
    Complex c4 = c2 * c3;
    std::cout << c4 << std::endl;  // ������� "-32 + 70i

    ++c1; // ���������� �������������� ����� �� 1, ��������� ���������� � c1
    Complex �6 = c1++; // ���������� �������������� ����� �� 1, �� ��������� ���������� � c2

    // ��������� ����� � ������ :
    Complex z;
    std::cout << "������� ����������� �����:" << std::endl;
    std::cin >> z;
    std::cout << z + 1;
    system("pause");
}