#include <iostream>
#include <cstddef>

int main() {
    setlocale(LC_ALL, "rus");
    const int N = 12;
    char* firstMas = new char[N] {1, 2, 3, 4, 5, 6, 7,8,9,10,11,12};
    char* secondMas = new char[N];

    const int n = 10;
    auto* newFirstMas = reinterpret_cast<size_t*>(firstMas);
    auto* newSecondMas = reinterpret_cast<size_t*>(secondMas);

    for (int i = 0; i < N / sizeof(size_t); i++) {
        newSecondMas[i] = newFirstMas[i];
    }

    char* remainingFirstMas = reinterpret_cast<char*>(newFirstMas);
    char* remainingSecondMas = reinterpret_cast<char*>(newSecondMas);

    for (int i = N / sizeof(size_t) * sizeof(size_t); i < N; i++) {
        remainingSecondMas[i] = remainingFirstMas[i];
    }

    for (int i = 0; i < N; i++) {
        std::cout << static_cast<int>(secondMas[i]) << " ";
    }

    std::cout << "Размер типа size_t: " << sizeof(size_t) << " байт" << std::endl;

    delete[] firstMas;
    delete[] secondMas;

    return 0;
}
