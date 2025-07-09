#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<long long> dp(n + 1, 0);

    for (int i = 0; i < min(5, n); ++i) {
        dp[i] = i;
    }

    for (int i = 5; i <= n; ++i) {
        dp[i] = max(dp[i - 4] * 4, max(dp[i - 3] * 3, dp[i - 2] * 2));
    }

    cout << dp[n];

    return 0;
}