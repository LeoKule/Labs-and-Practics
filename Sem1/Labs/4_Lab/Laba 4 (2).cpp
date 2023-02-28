#include <iostream>
using namespace std;
int main() {
	const int N = 1000;
	int mas[N];
	int sumOfDigits[N];
	int firstDigit[N];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> mas[i];
		int x = mas[i];
		sumOfDigits[i] = 0;
		while (x > 9)
		{
			sumOfDigits[i] += x % 10;
			x /= 10;
		}
		sumOfDigits[i] += x;
		firstDigit[i] = x;
	}
	for (int i = 0; i < n - 1; i++)
		for(int j=i+1;j<n;j++)
			if (sumOfDigits[i] > sumOfDigits[j] ||
				(sumOfDigits[i] == sumOfDigits[j] && firstDigit[i] > firstDigit[j]) ||
				(sumOfDigits[i] == sumOfDigits[j] && firstDigit[i] == firstDigit[j] && mas[i] > mas[j])) {
				swap(mas[i], mas[j]);
				swap(firstDigit[i], firstDigit[j]);
				swap(sumOfDigits[i], sumOfDigits[j]);
			}
		//if (первое условие или первое - нет, второе - да или первое, второе - нет, а третье - да) {

		//}

	for (int i = 0; i < n; i++){
		cout << mas[i] << endl;

	}
	



}