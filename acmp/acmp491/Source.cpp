#include <iostream>

using namespace std;

int main() {
	string str;
	cin >> str;

	bool p = false, b = true;
		
	for (int i = 0; i < str.length() / 2; ++i) {
		if (str[i] != str[str.length() - 1 - i]) {
			b = false;
		}
	}
	for (int i = 0; i < str.length() - 1; ++i) {
		if (str[i] != str[i + 1]) {
			p = true;
			break;
		}
	}
	if (!p) {
		cout << "NO SOLUTION";
	}
	else if (!b) {
		cout << str;
	} 
	else {
		for (int i = 0; i < str.length() - 1; ++i) {
			cout << str[i];
		}
	}
}