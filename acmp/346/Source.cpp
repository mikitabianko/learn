#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

inline void read(vector<int>& a) {
	string str;
	cin >> str;
	for (char& c : str) {
		a.push_back(c - '0');
	}
}

inline void removeZeros(vector<int>& a) {
	int i = 0;
	while (i + 1 < a.size() && a[i] == 0) ++i;
	a.erase(a.begin(), a.begin() + i);
}

inline vector<int> sub(vector<int>& a, vector<int>& b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<int> ans;
	int r = 0, ta, tb;
	for (int i = 0; i < max(a.size(), b.size()); ++i) {
		ta = (i < a.size() ? a[i] : 0);
		tb = (i < b.size() ? b[i] : 0);
		if (ta < tb - r) {
			ans.push_back(10 + ta - tb + r);
			r = -1;
		}
		else {
			ans.push_back(ta - tb + r);
			r = 0;
		}
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(ans.begin(), ans.end());
	removeZeros(ans);
	return ans;
}

inline bool g(vector<int>& a, vector<int>& b) {
	if (a.size() > b.size()) return true;
	if (a.size() < b.size()) return false;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i]) return true;
		if (a[i] < b[i]) return false;
	}
	return false;
}

inline bool f(vector<int> a, vector<int>& b, vector<int>& c) {
	removeZeros(a);

	if (g(a, c)) {
		return false;
	}

	vector<int> used(10, 0);
	for (int& el : b) {
		++used[el];
	}

	vector<int> d = sub(c, a);

	for (int& el : d) {
		--used[el];
	}

	for (int i = 0; i < 10; ++i) {
		if ((i == 0 && used[i] < 0) || (i != 0 && used[i] != 0)) {
			return false;
		}
	}

	b = d;

	return true;
}

inline void print(vector<int>& a) {
	int i = 0;
	while (i + 1 < a.size() && a[i] == 0) ++i;
	for (; i < a.size(); ++i) {
		cout << a[i];
	}
	cout << ' ';
}

int main() {
	vector<int> a, b, c;

	read(a);
	read(b);
	read(c);

	removeZeros(a);
	removeZeros(b);
	removeZeros(c);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	do {
		if (f(a, b, c)) {
			cout << "YES\n";
			print(a);
			print(b);
			return 0;
		}
	} while (next_permutation(a.begin(), a.end()));

	cout << "NO";

	return 0;
}