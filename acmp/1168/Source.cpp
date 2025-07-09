#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string>& a, pair<int, string>& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first > b.first;
}

int main() {

	int n, m, a, b, c;
	cin >> n >> m;

	vector<pair<int, string>> arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].second >> a >> b >> c;
		arr[i].first = a + b + c;
	}

	sort(arr.begin(), arr.end(), cmp);

	cout << arr[m - 1].second << ' ' << arr[m - 1].first;

	return 0;
}