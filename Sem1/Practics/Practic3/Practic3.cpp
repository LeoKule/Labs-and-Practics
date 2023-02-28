#include <iostream>
#include <fstream>
#include "Func.hpp"
#define size_str 33

int main()
{
	std::string all_lower = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
	std::string letter = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
	int countString[size_str] = { 0 };
	int index = 0;
	std::ifstream inn("text.txt", std::ios::in);
	setlocale(LC_ALL, "Rus");
	std::string s = "";
	std::string elem = "";
	std::cout << "Âאר עוךסע:" << std::endl << ReadFile(s) << std::endl;
	while (getline(inn, elem)) {
		for (int i = 0; i < all_lower.length(); i++) {
			countString[i] += std::count(elem.begin(), elem.end(), all_lower[i]);
		}
	}
	inn.close();
	SearchLetters(countString, letter);
	for (int i = 0; i < letter.length(); i++) {
		std::cout << letter[i] << " - " << countString[i] << std::endl;
	}
	FindWords(index, letter, s);
	system("pause");
}