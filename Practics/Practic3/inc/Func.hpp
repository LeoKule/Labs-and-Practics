#pragma once
#include <string>
std::string ReadFile(std::string &s);
void SearchLetters(int* countString, std::string &letter);
std::string FindWords(int index, std::string letter, std::string s);
std::string Register(std::string word, std::string letter);