#include <iostream>
#include <vector>

using namespace std;

inline void f(vector<vector<int>>& mat, int n) {
	if (n < 2) {
		mat[0][0] = 1;
		return;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n / 2; ++j) {
			mat[n - j - 1][n - i - 1] = mat[i][j];
		}
		for (int j = n / 2; j < n - i; ++j) {
			int next = (n + 1) - mat[i][n - j - 1];
			mat[i][j] = next;
			mat[n - j - 1][n - i - 1] = next;
		}
	}
}


int main() {
	int n;
	cin >> n;

	n = 1 << n;

	vector<vector<int>> mat(n, vector<int>(n));

	for (int k = 1; k <= n; k *= 2) {
		f(mat, k);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			mat[j][i] = mat[i][j] + n - 1;
		}
	}

	for (auto& row : mat) {
		for (auto& el : row) {
			cout << el << ' ';
		}
		cout << '\n';
	}
	return 0;
}