//projecteuler.net/problem=2
#include <iostream>

using namespace std;

int main() {

	int ans = 2;

	int dp[40];

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; dp[i - 1] < 4e6 && i < 40; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] < 4e6 && dp[i] % 2 == 0) {
			ans += dp[i];
		}
	}

	cout << ans; // 4613732

	return 0;
}