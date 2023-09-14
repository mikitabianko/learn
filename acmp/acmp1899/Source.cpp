#include <iostream>
#include <vector>

using namespace std;

int _k, _n, i;
vector<vector<short>> arr;

inline void f(int k, int m = 0) {
	if (m)
		arr.back()[_k - k - 1] = m;
	if (!k) return;
	do {
		f(k - 1, ++m);
		if (m < _n - k + 1)
			arr.push_back(arr.back());
	} while (m < _n - k + 1);
}

int main() {
	cin >> _n >> _k;

	arr.push_back(vector<short>(_k, 0));

	f(_k);

	for (auto& row : arr) {
		for (auto& el : row)
			cout << el << ' ';
		cout << '\n';
	}
}