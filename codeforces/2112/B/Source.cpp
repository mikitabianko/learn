#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int a, int mi, int ma) {
    return ((a + 1) >= mi && (a + 1) <= ma) 
        || ((a - 1) >= mi && (a - 1) <= ma)
        || ((a) >= mi && (a) <= ma);
}

int f(vector<int>& arr) {
    for (int k = 0; k < (int)arr.size(); ++k) {
        for (int i = 0; i < (int)arr.size() - k; ++i) {
            int mi = min(arr[i], arr[i + k]);
            int ma = max(arr[i], arr[i + k]);

            int l = (i == 0 ? (int)1e9 : arr[i - 1]);
            int r = (i == (int)arr.size() - k - 1 ? (int)1e9 : arr[i + k + 1]);

            if (check(l, mi, ma) || check(r, mi, ma))
                return k;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> arr(n);
        for (auto& el : arr) cin >> el;

        cout << f(arr) << "\n";
    }

    return 0;
}