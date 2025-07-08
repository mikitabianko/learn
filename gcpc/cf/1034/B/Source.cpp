#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t; cin >> t;

	while (t--) {
		int n, j, k; cin >> n >> j >> k;
		vector<int> arr(n); for(auto& el : arr) cin >> el;

		int a = arr[j - 1], count = 0;
		for (auto& el : arr) {
			if (el > a) count = 1;
		}
		if (1 + count > k) cout << "NO\n";
		else cout << "YES\n";
	}
    

	return 0;
}