#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define fs first
#define sc second

const uint INF = 1e9 + 7;

inline ull powMod(ull a, uint n, uint m) {
    a %= m;
    ull res = 1;
    while (n) {
        if (n & 1) res = (res * a) % m;
        n >>= 1;
        a = (a * a) % m;
    }
    return res % m;
}

inline uint gcd(uint a, uint b) {
    while (a != 0 && b != 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

ull g(pair<ull, ull> num) {
    return (num.fs * powMod(num.sc, INF - 2, INF)) % INF;
}

inline pair<ull, ull> toFraction(ld a){
    uint pT = 1;
    while (ull(a) != a) {
        a *= 10;
        pT *= 10;
    }
    uint fact = gcd(a, pT);
    return {a / fact, pT / fact};
}

const uint SIZE = 4 * 2e5 + 1;

uint t1[SIZE], t2[SIZE], add1[SIZE], add2[SIZE];

inline uint getV(uint* t, uint* add, uint v, uint l, uint r) {
    return (t[v] + (add[v] * (r - l + 1)));
}

inline void push(uint* t, uint* add, uint v) {
    add[2 * v + 1] = (add[2 * v + 1] + add[v]) % INF;
    add[2 * v] = (add[2 * v] + add[v]) % INF;
    add[v] = 0;
}

inline void upd(uint* t, uint* add, uint tl,  uint tr, uint v, uint ql, uint qr, uint val) {
    if (qr < ql) return;

    if (tl == ql && tr == qr) {
        add[v] = (add[v] + val) % INF;
        return;
    }
    push(t, add, v);
    uint m = (tl + tr) / 2;

    upd(t, add, tl, m, 2 * v, ql, min(m, qr), val);
    upd(t, add, m + 1, tr, 2 * v + 1, max(m + 1, ql), qr, val);

    t[v] = (getV(t, add, v * 2, tl, m) + getV(t, add, v * 2 + 1, m + 1, tr)) % INF;
}

inline uint get(uint* t, uint* add, uint tl,  uint tr, uint v, uint ql, uint qr) {
    if (qr < ql) return 0;

    if (tl == ql && tr == qr) {
        return getV(t, add, v, ql, qr);
    }
    push(t, add, v);
    uint m = (tl + tr) / 2;

    return (get(t, add, tl, m, 2 * v, ql, min(m, qr)) +
            get(t, add, m + 1, tr, 2 * v + 1, max(m + 1, ql), qr)) % INF;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);

    uint n, q; cin >> n >> q;
    ld p; cin >> p;

    auto temp = toFraction(1.0 - p);
    uint factor1 = g(temp);
    uint factor2 = g({temp.sc, temp.fs});

    char r; 
    uint b, x; 

    ull p1[200001], p2[200001];

    p1[0] = p2[0] = 1;

    for (int i = 1; i <= n; ++i) {
        p1[i] = (p1[i - 1] * factor1) % INF;
        p2[i] = (p2[i - 1] * factor2) % INF;
    }

    while (q--) {
        cin >> r;
        if (r == '+' || r == '-') {
            cin >> b >> x;

            ull start = ((b * p2[x]) % INF);
            ull start2 = ((b * p2[n - x]) % INF);

            if (r == '-') {
                start = INF - start;
                start2 = INF - start2;
            }
            upd(t1, add1, 1, n, 1, x, n, start);
            upd(t2, add2, 1, n, 1, 1, x - 1, start2);
        } else {
            cin >> x;

            cout << ((get(t1, add1, 1, n, 1, x, x) * p1[x]) % INF + 
                    (get(t2, add2, 1, n, 1, x, x) * p1[n - x]) % INF) % INF << "\n";
        }
    }

    return 0;
}