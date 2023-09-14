#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<short> _a, _b, _c;
short i, j;

inline void numToArray(int a, vector<short>& v) {
	while (a) {
		v.push_back(a % 10);
		a /= 10;
	}
}

inline void ArrayToNum(vector<short>& v, int& a) {
	a = 0;
	for (int i = v.size() - 1; i >= 0; --i) {
		a += v[i];
		a *= 10;
	}
	a /= 10;
}

vector<short>& f(vector<short>& a, vector<short>& b, short n) {
	if (n < _a.size())
		return a;
	return b;
}

inline bool f(short n = 0, short rest = 0) {
	if (n >= _c.size() && rest) return false;
	else if (n >= _c.size() && !rest) return true;

	for (i = n; i < _a.size(); ++i) {
		for (j = n; j < _b.size(); ++j) {
			if (_c[n] == (rest + _a[i] + _b[j]) % 10) {
				swap(_a[n], _a[i]);
				swap(_b[n], _b[j]);
				if (f(n + 1, (rest + _a[n] + _b[n]) / 10)) return true;
				swap(_a[n], _a[i]);
				swap(_b[n], _b[j]);
			}
		}
	}
	for (i = n; i < max(_a.size(), _b.size()); ++i) {
		if (_c[n] == (rest + f(_a, _b, n)[n]) % 10) {
			swap(f(_a, _b, n)[n], f(_a, _b, n)[i]);
			if (f(n + 1, (rest + f(_a, _b, n)[n]) / 10)) return true;
			swap(f(_a, _b, n)[n], f(_a, _b, n)[i]);
		}
	}
	rest += n < f(_a, _b, n).size() ? f(_a, _b, n)[n] : 0;
	if (rest != _c[n])
		return false;
	return f(n + 1, 0);
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	numToArray(a, _a);
	numToArray(b, _b);
	numToArray(c, _c);

	sort(_a.begin(), _a.end());
	sort(_b.begin(), _b.end());

	if (!f()) cout << "NO";
	else {
		cout << "YES\n";

		ArrayToNum(_a, a);
		ArrayToNum(_b, b);

		cout << a << ' ' << b;
	}
}