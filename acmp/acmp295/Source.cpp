#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string next(string str, int count = 1) {
	for (auto& c : str) {
		c = c + count;
		if (c < 'A') {
			c = 'Z' + c - 'A' + 1;
		}
		else if (c > 'Z') {
			c = (c - 'A') % ('Z' - 'A' + 1) + 'A';
		}
	}
	return str;
}

int main() {
	int n = 1e9;
	string s1, s2, ans;
	cin >> s1 >> s2;

	for (int i = 0; i <= 'Z' - 'A'; ++i) {
		if (s1.find(s2) != string::npos) {
			if (n > i % ('Z' - 'A' + 1)) {
				ans = next(s1, -i);
				n = i % ('Z' - 'A' + 1);
			}
		}
		s2 = next(s2);
	}

	if (ans == "") {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << ans;
	}
}