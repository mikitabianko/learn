#include <iostream>

using namespace std;
int main() {
	int n, dp[1001];
	cin >> n;

	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; ++i) 
		dp[i] = dp[i / 2] + dp[i - 2];

	cout << dp[n];
}