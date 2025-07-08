#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, long long> t;

inline void build(vector<int>& arr, int l, int r, int v) {
    if (l == r) {
        t[v] = arr[l];
        return;
    }

    int m = (l + r) / 2;

    build(arr, l, m, 2 * v);
    build(arr, m + 1, r, 2 * v + 1);

    t[v] = t[v * 2] + t[v * 2 + 1];
}

inline void upd(int tl, int tr, int v, int ind, int val) {
    if (tl == tr) {
        t[v] = val;
        return;
    }

    int m = (tl + tr) / 2;

    if (m >= ind) 
        upd(tl, m, 2 * v, ind, val);
    else
        upd(m + 1, tr, 2 * v + 1, ind, val);
    
    t[v] = t[v * 2] + t[v * 2 + 1];
}

inline long long get(int tl, int tr, int v, int ql, int qr) {
    if (qr < ql) return 0;

    if (tl == ql && tr == qr) {
        return t[v];
    }

    int m = (tl + tr) / 2;
    return get(tl, m, 2 * v, ql, min(qr, m)) + get(m + 1, tr, 2 * v + 1, max(m + 1, ql), qr);
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

    while (q--) {
        char a; int b, c; cin >> a >> b >> c;

        if (a == 's') 
            cout << get(0, n - 1, 1, b - 1, c - 1) << " ";
        else 
            upd(0, n - 1, 1, b - 1, c);
    }

    return 0;
}