#pragma once
#include <iostream>
#include <istream>
#include <stdexcept>
#include <cmath>

template<typename T,unsigned short N, unsigned short M>
class Matrix {
private:
    T data[N][M];
public:
    // Конструкторы
    Matrix() = default;

    Matrix(const Matrix& other) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                data[i][j] = other.data[i][j];

            }
        }
    }

    // Оператор присваивания копированием
    Matrix<T, N, M>& operator=(const Matrix<T, N, M>& other) {
        if (this != &other) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    // Операторы ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& matrix) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                os << matrix.data[i][j] << ' ';
            }
            os << '\n';
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Matrix<T, N, M>& matrix) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    // Операторы +, +=, *, *=
    // Оператор сложения матриц
    Matrix operator+(const Matrix<T,N,M>& other) {
        Matrix<T,N,M> result = *this;
        result += other;
        return result;
    }
    // Оператор сложения с присваиванием
    Matrix<T, N, M>& operator+=(const Matrix<T, N, M>& other) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    T get(unsigned short i, unsigned short j) const {
        return data[i][j];
    }

    T& set(unsigned short i, unsigned short j) {
        return data[i][j];
    }

    // Оператор умножения матриц
    //template<unsigned short Q, unsigned short W>
   /* Matrix<T, N, M> operator*(const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result{};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result(i, j) = T{0};
                for (int k = 0; k < M; k++) {
                    result(i, j) += data[i][k] * other(k, j);
                }
            }
        }
        return result;
    }*/

   template<unsigned short Q, unsigned short W>
   Matrix<T, N, W> operator* (const Matrix<T, Q, W>& other){
       Matrix<T, N, W> result{};
       if (M == Q){
           for (int i = 0; i < N; i++){
               for (int j = 0; j < W; j++){
                   result.set(i, j) = 0;
                   for (int k = 0; k < M; k++){
                       result.set(i, j) += data[i][k] * other.get(k, j);
                   }
               }
           }
       }
       return result;
   }

    // Оператор умножения с присваиванием
    /*template <size_t P>
    Matrix& operator*=(const Matrix<T, M, P>& other) {
        *this = *this * other;
        return *this;
    }*/

    Matrix<T, N, M>& operator*=(const Matrix<T, N, M>& other) {
        *this = *this * other;
        return *this;
    }


    Matrix<T, N, M>& operator++() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j]++;
            }
        }
       return *this;
    }
    T determinant() {
        if (N == M && M == 2) {
            return static_cast<T>(data[0][0] * data[1][1] - data[1][0] * data[0][1]);
        } else if (N == M && M == 3) {
            return static_cast<T>(data[0][0] * data[1][1] * data[2][2] + data[1][0] * data[0][2] * data[2][1] +
                                     data[0][1] * data[2][0] * data[1][2] - data[0][2] * data[1][1] * data[2][0] -
                                     data[0][0] * data[1][2] * data[2][1] - data[2][2] * data[0][1] * data[1][0]);
        } else if (N == M && M == 1) {
            return static_cast<T>(data[0][0]);
        }
    }


    T& operator()(size_t i, size_t j) {
        return data[i][j];
    }

    const T& operator()(size_t i, size_t j) const {
        return data[i][j];
    }


};