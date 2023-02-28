#include "func.hpp"
#include <iostream>
#include <string>

void encryption::Encode()
{
	int n = 0;							//разбиение строки на массив слов
	while (m_text.find(" ") != (-1))
	{
		int k = m_text.find(" ");
		m_words[n] = m_text;
		m_words[n].erase(k);
		m_text.erase(0, k+1);
		n += 1;
	}
	m_words[n] = m_text;
	m_WordsQuantity = n + 1;			//количество слов в строке
	if (m_WordsQuantity > 30)
	{
		std::cout << "Error.Too many words per line" << "\n";
		
	}

	m_NumFib[0] = 1;						//создание массива из последовательности фиббоначи
	m_NumFib[1] = 2;
	for (int i = 2; i < 30; i++)
	{
		m_NumFib[i] = m_NumFib[i - 1] + m_NumFib[i - 2];
	}
	for (int i = 0; i < 30; i++)
	{
		std::cout << m_NumFib[i] << " ";
	}
	std::cout << "\n";
}

bool encryption::Test(int Cipher[30])
{
	for (int i = 0; i < m_WordsQuantity; i++)
	{
		bool TestCipherIsNum = false;
		for (int j = 0; j < m_WordsQuantity; j++)
		{
			if (i != j)
			{
				if (Cipher[i] == Cipher[j])				//проверка, нет ли в ключе одинаковых чисел
				{
					std::cout << "Error. Mumbers cannot be repeated" << "\n";
					return 0;
				}
					
			}
			
			if (Cipher[i] == m_NumFib[j])
			{
				TestCipherIsNum = true;    //проверка, является ли число элементом последовательности фиббоначи

			}
		}
		if (TestCipherIsNum == false)
		{
			std::cout << "Error. The number " << Cipher[i] << " does not belong to the sequence";
			return 0;
		}
	}
	return 1;
}

void encryption::Decode(int Cipher[30])
{
	int Num[30];
	for (int i = 0; i < m_WordsQuantity; i++)
	{
		for (int j = 0; j < m_WordsQuantity; j++)
		{
			if (Cipher[i] == m_NumFib[j])
			{
				Num[i] = j;
			}
		}
	}
	for (int i = 0; i < m_WordsQuantity; i++)
	{
		m_cipher[i] = m_words[Num[i]];
		std::cout << m_cipher[i] << " ";
	}
	std::cout << "\n";
}