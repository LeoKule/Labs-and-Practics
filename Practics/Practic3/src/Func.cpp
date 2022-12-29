#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Func.hpp"
#define size_alph 33

std::string ReadFile(std::string &s) {
	std::ifstream in("text.txt", std::ios::in);
	if (!in.is_open())
	{
		std::cout << "Error" << std::endl;
	}
	std::string m = "";
	while (!in.eof()) {
		in >> m;
		transform(m.begin(), m.end(), m.begin(), ::tolower);
		s += m + " ";
	}
	return s;
	in.close();
}
void SearchLetters(int *countString, std::string &letter) {
	for (int i = 0; i < size_alph; i++) {
		for (int j = i; j < size_alph; j++) {
			if (countString[i] < countString[j]) {
				std::swap(countString[i], countString[j]);
				std::swap(letter[i], letter[j]);
			}
		}
	}
	letter.resize(8);
}

std::string Register(std::string word, std::string letter){
	std::string B = "";
	std::string bracket = "";
	for (int i = 0; i < word.size(); i++) {
		char tempLiter = word[i];
		bool flagL = false;
		for (int j = 0; j < letter.size(); j++) {
			if (tempLiter == letter[j]) {
				B += toupper(word[i]);
				bracket += toupper(word[i]);
				flagL = true;
				break;
			}

		}
		if (flagL == false) {
			B += word[i];
		}
	}

	return B + " (" + bracket + ")";
}

std::string FindWords(int index, std::string letter, std::string s) {
	std::ifstream word("text.txt", std::ios::in);
	std::ofstream output("Output.txt", std::ios::out);
	std::string L;
	std::string regist_word = "";
	int c = 0;
	bool flags[8] = { 0 };
	if (!word.is_open()) {
		std::cout << "Error word" << std::endl;
	}
	for (int i = 0; !word.eof(); i++) {
		if (!word.eof()) {
			word >> L;
			for (int i = 0; i < L.length(); i++) {
				if (L[i] == letter[0]) {
					flags[0] = true;
				}
				if (L[i] == letter[1]) {
					flags[1] = true;
				}
				if (L[i] == letter[2]) {
					flags[2] = true;
				}
				if (L[i] == letter[3]) {
					flags[3] = true;
				}
				if (L[i] == letter[4]) {
					flags[4] = true;
				}
				if (L[i] == letter[5]) {
					flags[5] = true;
				}
				if (L[i] == letter[6]) {
					flags[6] = true;
				}
				if (L[i] == letter[7]) {
					flags[7] = true;
				}
			}

		}
		short tempSumm = 0;
		for (int i = 0; i < std::size(flags); i++) {
			tempSumm += (short)flags[i];
		}
		// объ€вление новой пустой переменной, которую будем записывать в аутпут

		if (tempSumm >= 5) {
			// вызов функции
			regist_word = Register(L,letter);
		}
		else{
			regist_word = L;
		}
		//запись в аутпут тииксти
		
		output << regist_word + " ";
		for (int i = 0; i < 8; i++) {
			flags[i] = 0;

		}
	}
	return L;
}