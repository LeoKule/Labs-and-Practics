#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");

	int n;
	cout << "������� ��� ������...\n";
	cin >> n;

	switch (n)
	{
	case 12:
		cout << "����\n";
		break;
	case 20:
		cout << "������\n";
		break;
	case 8:
		cout << "���\n";
		break;
	case 31:
		cout << "�������\n";
		break;
	case 26:
		cout << "��������\n";
		break;
	default:
		cout << "������ ��� ������ �����������\n";
		break;




	}

}

