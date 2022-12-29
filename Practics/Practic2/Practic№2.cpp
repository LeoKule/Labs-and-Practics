#include <iostream>
#include <fstream>
#include "Func.hpp"
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	cout << "Sum" << endl << sum_long_and_long(a, b) << endl;
	cout << "Multi" << endl << multi_long_and_long(a, b) << endl;
}