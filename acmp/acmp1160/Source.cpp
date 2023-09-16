#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;

	vector<int> pref(str.length(), 0);

	for (int i = 1; i < str.length(); ++i) {
		int k = pref[i - 1];
		while (k > 0 && str[i] != str[k]) {
			k = pref[k - 1];
		}
		if (str[i] == str[k])
			k++;
		pref[i] = k;

	}

	for (auto& el : pref) {
		cout << el << ' ';
	}
}