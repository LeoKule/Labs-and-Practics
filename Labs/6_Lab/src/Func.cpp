#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <Func.hpp>

void WritingToFille(int Mat[100][100], int& n, int& m) {
	std::ofstream out("Output.txt", std::ios::out);
	out << n << std::endl;
	out << m << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			out << Mat[i][j] << " ";
		}
		out << "\n";
	}
	out.close();
}
void ReadFile(int Mat[100][100], int& n, int& m) {
	std::ifstream in("C:/Users/Чипырик/Desktop/Build/assets/input.txt", std::ios::in);
	while (!in.eof()) {
		in >> n;
		in >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				in >> (Mat[i][j]);
			}
		}
	}
	in.close();
}	
void MatrixProcessing(int Mat[100][100], int n) {
	// хочу найти 3 и 5 в числе :(
	// ну и ещё они должны быть больше нуля.
	// Затем заменить мин эл столбца на сумму квадратов этого же столбца
	for (int i = 0; i < n; i++) {
		bool HAVE = false;
		int x = Mat[i][i];
		if (x > 0) {
			while (x > 0) {
				if (x % 10 == 3 || x % 10 == 5) {
					HAVE = true;
					break;
				}
				x /= 10;
			}
			if (HAVE) {
				continue;
			}
			else break;
		}
		else break;
	}

	int ExponentiationSum = 0;
	for (int i = 0; i < n; i++) {
		int min = INT_MAX;
		int l;
		for (int j = 0; j < n; j++) {
			ExponentiationSum += Mat[j][i] * Mat[j][i];
			if (Mat[j][i] < min) {
				min = Mat[j][i];
				l = j;
			}
		}
		Mat[l][i] = ExponentiationSum;
	}
}