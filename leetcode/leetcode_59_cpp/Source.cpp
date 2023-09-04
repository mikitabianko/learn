#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	auto mat = vector<vector<int>>(n, vector<int>(n, 0));

	for (int k = 0, el = 1; el <= n * n; ++k) {
		for (int i = k; i < n - k; ++i)
			mat[k][i] = el++;
		for (int i = k + 1; i < n - k; ++i)
			mat[i][n - k - 1] = el++;
		for (int i = n - k - 2; i >= k; --i)
			mat[n - k - 1][i] = el++;
		for (int i = n - k - 2; i > k; --i)
			mat[i][k] = el++;
	}

	return mat;
}

int main() {
	for (auto& row : generateMatrix(10)) {
		for (auto& el : row) 
			cout << el << ' ';
		cout << '\n';
	}
}