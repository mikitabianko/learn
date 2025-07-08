#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, pair<int, int>> t;  // value, int

inline void build(vector<int>& arr, int tl, int tr, int v) {
    if (tl == tr) {
        t[v] = {arr[tl], tl}; 
        return;
    }
    
    int m = (tl + tr) / 2;

    build(arr, tl, m, 2 * v);
    build(arr, m + 1, tr, 2 * v + 1);

    t[v] = max(t[2 * v], t[2 * v + 1]);
}

inline pair<int, int> get(int tl, int tr, int v, int ql, int qr) {
    if (ql > qr) return {0, 0};

    if (qr == tr && ql == tl) return t[v];

    int m = (tl + tr) / 2;

    return max(get(tl, m, 2 * v, ql, min(qr, m)), get(m + 1, tr, 2 * v + 1, max(m + 1, ql), qr));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n; cin >> n;

    vector<int> arr(n);
    for (auto& el : arr) cin >> el;

    build(arr, 0, n - 1, 1);

    int q; cin >> q;

    int a, b;

    while (q--) {
        cin >> a >> b;

        auto ans = get(0, n - 1, 1, a - 1, b - 1);

        cout << ans.first << ' ' << ans.second + 1 << '\n';
    }

    return 0;
}