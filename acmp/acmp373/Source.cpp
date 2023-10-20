#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> mat(n, vector<int>(n));

	for (auto& row : mat) {
		for (auto& el : row) {
			cin >> el;
		}
	}

	vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(n + 2, vector<int>(2, 0)));

	dp[1][1][0] = mat[0][0];

	for (int k = 1; k < m; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int temp = max({	dp[i + 1][j][(k + 1) % 2], dp[i - 1][j][(k + 1) % 2], 
									dp[i][j + 1][(k + 1) % 2], dp[i][j - 1][(k + 1) % 2]	});

				if (temp != 0) {
					dp[i][j][k % 2] = dp[i][j][(k + 1) % 2] + temp + mat[i - 1][j - 1];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ans = max(ans, dp[i][j][(m + 1) % 2]);
		}
	}
	cout << ans;

	return  0;
}