#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int t, k, q, ma, a, n;

    cin >> t;

    while (t--) {
        cin >> k >> q;
        ma = 1e9;
        while (k--) {
            cin >> a;
            ma = min(ma, a);
        }
        while (q--) {
            cin >> n;
            cout << min(n, ma - 1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}