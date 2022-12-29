#include <iostream>
#include <fstream>
#include <Func.hpp>
#include <string>

int main()
{
	setlocale(LC_ALL, "Rus");
	int rows;
	int cols;
	int const N = 100;
	int const M = 100;
	int Matrix[N][M];
	ReadFile(Matrix, rows, cols);

	std::cout << rows << std::endl << cols << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << Matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	MatrixProcessing(Matrix, rows);
	std::cout << std::endl;


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << Matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	WritingToFille(Matrix, rows, cols);
}