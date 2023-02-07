#pragma once
#include <string>
#include <iostream>
#include <string>

class encryption
{
private:
	std::string m_text;
	std::string m_words[30];
	std::string m_cipher[30];
	int m_NumFib[30];
	int m_WordsQuantity;
public:
	encryption(const std::string& text)
	{
		m_text = text;
	}
	~encryption() {}

	void Encode();
	void Decode(int Cipher[30]);
	bool Test(int Cipher[30]);
	int getCount() const
	{
		return m_WordsQuantity;
	}
};