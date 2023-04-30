#include <iostream>
#include "Matrix.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Matrix<int, 2, 2> m1{};

    std::cout << "m1" << std::endl;
    std::cin >> m1;
    std::cout << "m1" << std::endl << m1 << std::endl;

    Matrix<int, 2, 2> m2{};

    std::cout << "m2:" << std::endl;
    std::cin >> m2;
    std::cout << "m2:" << std::endl << m2 << std::endl;
    Matrix<int,2,2> m3{};
    Matrix<int,2,2> m4 = m1;
    std::cout << "m4=m1:" << std::endl << m4 <<std::endl;
    Matrix<int,2,2> m5{};
    m3 = m2;
    std::cout << "m3=m2:" << std::endl << m3 <<std::endl;
    m3 += m1;
    std::cout << "m3+=m1:" << std::endl << m3 <<std::endl;
    m4 = m1 + m3;
    std::cout << "m4=m1+m3:" << std::endl << m4 <<std::endl;
    ++m5;
    std::cout << "m5:" << std::endl << m5 <<std::endl;
    m5 = m1 * m2;
    std::cout << "m5=m1*m2:" << std::endl << m5 << std::endl;
    std:: cout << "det(m2):" << std::endl <<m2.determinant() << std::endl;
    m1 *= m2;
    std::cout << "m1*=m2:" << std::endl << m1 << std::endl;
    ++m4;
    std::cout << "++m4:" << std::endl << m4 <<std::endl;
    std::cout << m4(1,1) << std::endl;

    return 0;
}
