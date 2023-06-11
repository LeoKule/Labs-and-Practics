#include <iostream>

template <typename T>
void copyArray(const T* source, T* destination, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}

int main()
{
    const int N = 1000000; // Пример размера массива N

    // Создание и заполнение исходного массива
    int* sourceArray = new int[N];
    for (int i = 0; i < N; ++i) {
        sourceArray[i] = i;
    }

    // Создание и выделение памяти для массива-назначения
    int* destinationArray = new int[N];

    // Копирование содержимого исходного массива в массив-назначение
    copyArray(sourceArray, destinationArray, N);

    // Проверка результатов
    for (int i = 0; i < N; ++i) {
        if (destinationArray[i] != sourceArray[i]) {
            std::cout << "Ошибка: содержимое массивов не совпадает!" << std::endl;
            break;
        }
    }

    // Освобождение памяти
    delete[] sourceArray;
    delete[] destinationArray;

    return 0;
}
//В данном случае мы используем простой цикл для копирования каждого элемента
//из исходного массива в массив-назначение.
//Каждая итерация цикла выполняет присваивание одного элемента, и таким образом, общая сложность копирования составляет O(N), где N - размер массива.
//Кроме того, данный подход позволяет эффективно работать с массивами любого типа данных, так как в шаблонной функции copyArray
//используется параметр шаблона typename T, который позволяет нам копировать элементы произвольного типа.