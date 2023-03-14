#include <iostream>
#include "String.h"

int main() {
    String s1; // default constructor
    std::cout << "s1: " << s1 << std::endl;

    String s2("hello"); // parameterized constructor
    std::cout << "s2: " << s2 << std::endl;

    String s3(s2); // copy constructor
    std::cout << "s3: " << s3 << std::endl;

    s1 = s2; // copy assignment operator
    std::cout << "s1 after copy assignment: " << s1 << std::endl;

    String s4 = s1 + s3; // concatenation using + operator
    std::cout << "s4 after concatenation: " << s4 << std::endl;

    s1 += s2; // concatenation using += operator
    std::cout << "s1 after concatenation: " << s1 << std::endl;

    std::cout << "s2[0]: " << s2[0] << std::endl; // accessing element at index 0
    s2[0] = 'H'; // changing element at index 0
    std::cout << "s2 after changing element at index 0: " << s2 << std::endl;

    std::cout << "s1 == s2: " << (s1 == s2) << std::endl; // comparison using == operator
    std::cout << "s1 < s2: " << (s1 < s2) << std::endl; // comparison using < operator

    std::cout << "Enter a String: ";
    std::cin >> s1; // input using >> operator
    std::cout << "You entered: " << s1 << std::endl;

    std::cout << "Length of s1: " << s1.length() << std::endl; // length method

    const char* cstr = s1.c_str(); // c_str method
    std::cout << "c_str of s1: " << cstr << std::endl;

    std::cout << "Index of 'e' in s1: " << s1.find('e') << std::endl; // find method

    std::cout << "Index of 0 in s2 : " << s2.at(0) << std::endl;  // at method

    try {
        std::cout << s2.at(12) << std::endl; // Should throw out_of_range exception
    }
    catch (std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }


    return 0;
}