#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, a, l, m, r, ans = 0;
	cin >> n;

	vector<int> dp(n, 1e9);

	while(n--) {
		cin >> a;

		l = 0;
		r = ans + 1;
		
		while (l < r) {
			m = (l + r) / 2;
			if (dp[m] >= a) r = m;
			else l = m + 1;
		}

		dp[l] = a;

		ans = max(ans, l);
	}
	cout << ans + 1;
}