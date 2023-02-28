/*Дан файл, содержащий русский текст, размер текста не превышает 10 К байт.
Найти в тексте N (N ≤ 100) самых длинных слов, не содержащих одинаковых букв.
Записать найденные слова в текстовый файл в порядке не возрастания длины. Все найденные слова должны быть разными. Число N вводить из файла.*/

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <ctype.h>
#include <windows.h>
using namespace std;

int main() {


	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//char str[100];
	string s, t[10000], c[100];
	int y = 0;
	


	ifstream in("Tekst.txt", std::ios::in);
	if (!in.is_open())
	{
		std::cout << "Error" << std::endl;
		return -1;
	}

	while (!in.eof()) {
		int count = 1;
		int cnt = 0;
		in >> s;
		string t1 = s;
		transform(t1.begin(), t1.end(), t1.begin(), ::tolower);
		//убираем знаки:
		for (int i = 0; i < s.length(); i++) {
			if (ispunct(((unsigned char)t1[i])) != 0) {
				t1.erase(i);
			}
		}
		//Проверка на неналичие одинаковых букв, и запись в массив.
		int buk = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 1; j < s.length(); j++) {
				if (t1[i] == t1[j]) {
					buk++;
				}
			}
		}
		if (buk == 0) {
			int Y = y;
			for (int i = 0; i < Y; i++) {
				string t2 = t[i];
				cnt = 0;
				if (t1 == t2) {
					cnt += 1;
					break;
				}
			
			}
			if (cnt == 0) {
				t[y] = t1;
				y++;
			}
			
		}
	}
	in.close();
	//Убираем одинаковые слова, и сортируем по убыванию.
	int wordNum = y;
	for (int j = 0; j < wordNum; j++) {
		for (int i = j + 1; i < wordNum; i++) {
			if (t[j].length() < t[i].length()) {
				swap(t[j], t[i]);
			}
		}
	}
	//Запись из рабочего массива в итоговый
	ofstream otvet("otvet.txt");
	for (int i = 0; i < 100; i++) {
		c[i] = t[i];
		otvet << c[i] << " ";
		cout << c[i] << endl;
	}
	otvet.close();

}