#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, long long> t;

inline void build(vector<int>& arr, int tl, int tr, int v) {
    if (tl == tr) {
        t[v] = arr[tl];
        return;
    }

    int m = (tl + tr) / 2;

    build(arr, tl, m, 2 * v);
    build(arr, m + 1, tr, 2 * v + 1);

    t[v] = t[2 * v] + t[2 * v + 1];
}

inline long long get(int tl, int tr, int v, int ql, int qr) {
    if (ql > qr) return 0;

    if (tl == ql && qr == tr) 
        return t[v];

    int m = (tl + tr) / 2;

    return get(tl, m, 2 * v, ql, min(m, qr)) + get(m + 1, tr, 2 * v + 1, max(m + 1, ql), qr);
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
        cout << get(0, n - 1, 1, a - 1, b - 1) << ' ';
    }

    return 0;
}