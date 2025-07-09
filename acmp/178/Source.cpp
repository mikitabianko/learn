#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	map<int, int> mp;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		++mp[arr[i]];
	}

	pair<int, int> m = {0, 0};

	for (auto& el : mp) {
		if (m.second < el.second) {
			m = el;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] != m.first) {
			cout << arr[i] << ' ';
		}
	}
	for (int i = 0; i < m.second; ++i) {
		cout << m.first << ' ';
	}
	return 0;
}