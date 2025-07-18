#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        int ans = 9;
        while (n) {
            ans = min(ans, n % 10);
            n /= 10;
        }

        cout << ans  << "\n";
    }

    return 0;
}