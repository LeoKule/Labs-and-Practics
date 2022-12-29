#include <iostream>
using namespace std;
int main() {
	float multi = 1;
	int index;
	float min = 10000;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		float tempNumber;
		cin >> tempNumber;
		int Num = tempNumber;
		//1.5
		//1

		//1
		//1
		//здесь число уже есть
		if (tempNumber < 0 and tempNumber != Num) {
			multi = multi * tempNumber;
			if (tempNumber < min) {
				min = tempNumber;
				index = i;

			}
		}
		//if (отрицательное и есть дробная часть){
			//алгоритм;
		//}



	}
	cout << multi << " " << " " << min << " " << " " << index << endl;
}







