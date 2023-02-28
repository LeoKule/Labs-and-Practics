#include <iostream>
using namespace std;
int main() {
	int matrix[100][100];
	int n;
	int m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int sum_max = -1;
	int index = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += abs(matrix[i][j]);

		}
		if (sum_max < sum) {
			sum_max = sum;
			index = i;

		}
	}
	for (int j = 0; j < m; j++) {
		matrix[index][j] = 9999;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}