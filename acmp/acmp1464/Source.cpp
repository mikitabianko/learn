#include <iostream> //a[i+1] = (k * a[i]+b) mod m.
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, a, k, b, m, l, r, mm, s = 1;

	cin >> n >> a >> k >> b >> m;

	vector<int> arr(n), way(n, -1);
	vector<pair<int, int>> dp(n, {1e9, 0});

	for (int i = 0; i < n; ++i) {
		arr[i] = a;
		l = 0;
		r = s;

		while (l < r) {
			mm = (l + r) / 2;
			if (dp[mm].first >= a) r = mm;
			else l = mm + 1;
		}

		dp[l] = { a, i };

		way[i] = l ? dp[l - 1].second : -1;

		s = max(s, l + 1);

		a = ((k % m) * (a % m) % m + b) % m;
	}

	vector<int> ans;
	ans.reserve(s);

	int p = dp[s - 1].second;
	while (p != -1) {
		ans.push_back(arr[p]);
		p = way[p];
	}
	while (s--) cout << ans[s] << ' ';
}