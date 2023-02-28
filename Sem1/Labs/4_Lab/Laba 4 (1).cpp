#include <iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	const int N = 10000;
	bool Sum19 = false;
	int sum;
	int mas[N];
	int digit[N];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//проверка на сумму цифр в 19
		sum = 0;
		cin >> mas[i];
		int Num = mas[i];
		while (Num > 9) {
			int digit = Num % 10;
			sum += digit;
			Num /= 10;

		}
		sum += Num;
		if (sum == 19) {
			Sum19 = true;
		}


	//	else {

	//for (int i = 0; i < n; i++)
	//	cout << sum << " " << mas[i] << endl;
	}
	if (Sum19 == false){
		//проверка переменной sum19:
		//если сумму такой нет, то сортировка
		//сортировка
		for (int i = 0; i < n - 1; i++){
			for (int j = i + 1; j < n; j++) {
				if (mas[i] < mas[j]) {
					int tmp = mas[i];
					mas[i] = mas[j];
					mas[j] = tmp;
				}
				}
			}
		for (int i = 0; i < n; i++) {
			cout << mas[i] << " ";
		}
	}
	else if (Sum19 == true){
		cout << "В последовательности есть число с суммой цифр, равной 19";
	}
	
}
