#include <iostream>

int main() {
	unsigned long long a = 1234567891011121314;
	unsigned char* firstByte = (unsigned char*)&a;
	unsigned char test[8];
	//std::cout << (int)*firstByte << " " << (int)*(firstByte + 1) << " " << (int)*(firstByte + 2) << " " << (int)*(firstByte + 3) << " " << (int)*(firstByte + 4) << " " << (int)*(firstByte + 5) << " " << (int)*(firstByte + 6) << " " << (int)*(firstByte + 7) << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << (int)*(firstByte + i) << " ";
	}
}