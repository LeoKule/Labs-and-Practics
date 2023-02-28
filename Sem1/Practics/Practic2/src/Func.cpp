#include <iostream>
#include <algorithm>
#include "Func.hpp"
#define len length()
using namespace std;
string sum_long_and_long(string a, string b) {
	string c;
	while (a.len != b.len) {
		if (a.len < b.len)
			a = "0" + a;
		else
			b = "0" + b;
	}
	a = "0" + a;
	b = "0" + b;
	int sum, r = 0;
	for (int i = a.len - 1; i > -1; i--) {
		sum = a[i] - '0' + b[i] - '0' + r;
		r = sum / 10;
		c = char(sum % 10 + '0') + c;
	}
	if (c[0] == '0')
		c.erase(0, 1);
	return c;
}
string multi_long_and_long(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int index = 0;
	string c = "";
	const int ans_size = 2000;
	int ans[ans_size] = { 0 };
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			int p = a[i] - '0';
			int q = b[j] - '0';

			ans[i + j] += p * q;
			ans[i + j + 1] = ans[i + j + 1] + ans[i + j] / 10;
			ans[i + j] %= 10;
		}
	}
	for (int i = 0; i < (a.size() + b.size()); i++) {
		c += to_string(ans[i]);
	}
	reverse(c.begin(), c.end());
	if (c[0] == '0') {
		c.erase(0, 1);
	}
	return c;
}
