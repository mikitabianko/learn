#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> b(n, 0), arr(n); for (auto& el : arr) cin >>  el;

        int a = arr[0];
        for (int i = 0; i < n; ++i) {
            a = min(a, arr[i]);
            if (a == arr[i]) b[i] = 1;
        }
        a = arr[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            a = max(a, arr[i]);
            if (a == arr[i]) b[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i];
        }
        cout << "\n";
    }    

	return 0;
}