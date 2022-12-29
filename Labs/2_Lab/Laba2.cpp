#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");

	int n;
	cout << "Ввидите код товара...\n";
	cin >> n;

	switch (n)
	{
	case 12:
		cout << "Яйцо\n";
		break;
	case 20:
		cout << "Молоко\n";
		break;
	case 8:
		cout << "Сыр\n";
		break;
	case 31:
		cout << "Помидор\n";
		break;
	case 26:
		cout << "Кукуруза\n";
		break;
	default:
		cout << "Данный код товара отсутствует\n";
		break;




	}

}

