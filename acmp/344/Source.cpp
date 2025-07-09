#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}

	sort(arr.begin(), arr.end());

	int ans = INT_MAX;
	pair<int, int> points;

	for (int i = 0; i < n - 1; ++i) {
		if (ans > abs(arr[i].first - arr[i + 1].first)) {
			ans = abs(arr[i].first - arr[i + 1].first);
			points.first = arr[i].second;
			points.second = arr[i + 1].second;

		}
	}

	cout << ans << '\n' << points.first << ' ' << points.second;

	return 0;
}