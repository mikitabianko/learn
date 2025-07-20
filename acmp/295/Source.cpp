#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string f(string str, int n) {
	for (auto& el : str) {
		el = (el - 'A' + n + 26) % 26 + 'A';
	}
	return str;
}

bool find(string a, string b) {
	string str = b + "#" + a;
	vector<int> p(str.length(), 0);
	for (int i = 1; i < str.length(); ++i) {
		int c = p[i - 1];
		while (c > 0 && str[i] != str[c]) c = p[c - 1];
		if (str[i] == str[c]) p[i] = c + 1;

		if (p[i] == b.length()) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	string a, b; cin >> a >> b;

	for (int i = 0; i < 27; ++i) {
		if (find(a, f(b, i))) {
			cout << f(a, -i);
			return 0;
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}