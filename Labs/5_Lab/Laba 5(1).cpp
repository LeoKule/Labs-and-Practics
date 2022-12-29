#include <iostream>
#include <string>
#include <fstream>
int main() {
	char str[100] = "FsdAdddAAAdddFFrrrr";
	char ch[100];
	int max = 0;
	char letter;

	for (int i = 0; i < strlen(str); i++) 
		ch[i] = tolower(str[i]);
	ch[strlen(str)] = 0;

	for (int i = 0; i < strlen(ch); i++) {
		int count = 1;
		for (int j = i+1; j < strlen(ch)-1; j++) {
			if (ch[i] == ch[j]) {
				count += 1;
				
			}
		}
		if (max < count) {
			max = count;
			letter = ch[i];
		}

	
	}
	std::cout << letter << " " << max << std::endl;
}
