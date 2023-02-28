#include <iostream>
#include "func.hpp"
#include <string>

int main()
{
	std::string Text;
	std::cout << "Enter a Message" << "\n";
	getline(std::cin, Text);

	encryption Message(Text);
	if (Message.getCount() <= 30)
	{
		Message.Encode();

		std::cout << "Enter the code" << "\n";
		int Cipher[30];
		for (int i = 0; i < Message.getCount(); i++)
		{
			std::cin >> Cipher[i];
		}
		if(Message.Test(Cipher) == 1)
		{
			Message.Decode(Cipher);
		}
	}
}