#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> t, add;

inline int getV(int v, int l, int r) {
    return add[v] * (r - l + 1) + t[v];
}

void push(int v) {
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    add[v] = 0;
}

int f(int a, int b) {
    return a + b;
}

int get(int tl, int tr, int v, int ql, int qr) {
    if (ql > qr) return 0;
    if (ql == tl && qr == tr) return getV(v, ql, qr);

    int m = (tl + tr) / 2;

    return f(get(tl, m, 2 * v, ql, min(qr, m)), get(m + 1, tr, 2 * v + 1, max(m + 1, ql), qr)) + add[v] * (qr - ql + 1);
}

void upd(int tl, int tr, int v, int ul, int ur, int val) {
    if (ul > ur) return;
    if (ul == tl && ur == tr) {
        add[v] += val;
        return;
    }

    push(v);
    int m = (tl + tr) / 2;

    upd(tl, m, v * 2, ul, min(m, ur), val);
    upd(m + 1, tr, v * 2 + 1, max(m + 1, ul), ur, val);

    t[v] = getV(v * 2, tl, m) + getV(v * 2 + 1, m + 1, tr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, m; cin >> n >> m;
    int a, b, c, d;

    while(m--) {
        cin >> a >> b >> c; 
        if (a == 1) {
            cin >> d;
            upd(0, n, 1, b, c - 1, d);
        } else {
            cout << get(0, n, 1, b, c - 1) << "\n";
        }
    }

    return 0;
}