#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--) {
        int n, k; cin >> n >> k;

        int ans = 0, count = 0, t;

        while (n--) {
            cin >> t;
            if (t) {
                ans += (count / (k + 1));
                if (count % (k + 1) >= k) ++ans;
                count = 0;
                continue;
            }
            ++count;
        }
        ans += (count / (k + 1));
        if (count % (k + 1) >= k) ++ans;

        cout << ans << '\n';
    }

    return 0;
}