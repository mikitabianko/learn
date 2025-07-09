#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int mex(map<int, int>& arr) {
    int prev = -1;
    for (auto& el : arr) {
        if (el.first - 1 != prev) break;
        prev = el.first;
    }
    return prev + 1;
}

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        map<int, int> a;
        for (int i = 0; i < n; ++i) {
            int b; cin >> b;
            a[b]++;
        }
        int m = mex(a);
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n + 1; ++i) {
            dp[i] = n + 1 - i;
        }
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            int count = 0;
            for (auto& el : a) {
                if (el.first > m) { break; }
                if (el.first == i) dp[i]++;
                if (el.second >= i) {
                    for (int j = 1; j < i; ++j) dp[i] += dp[j];
                }
            }
        }

        for (auto& el : dp) cout << el << " ";

        cout << "\n";
    }    

	return 0;
}