#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        int ans = 0;
        vector<int> a(k);

        for (auto& el : a) cin >> el;

        sort(a.begin(), a.end());

        for (int i = 0; i < k - 1; ++i) {
            ans += 2 * a[i] - 1;
        }

        cout << ans << '\n';
    }
}