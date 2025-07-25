#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#ifndef LOCAL
#include <bits/stdc++.h>
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define fs first
#define sc second
#define SZ(a) a.size()
#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define PB push_back

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define trav(a, x) for (auto &a : x)

#define in(x) int x; cin >> x;
#define inll(x) ll x; cin >> x;
#define inv(v) trav(i, v) cin >> i;
#define invv(v) trav(i, v) inv(i);
#define outv(v) trav(i, v) cout << i << ' ';
#define outvv(v) trav(i, v) { outv(i); cout << '\n'; }
#define sortall(v) sort(ALL(v));
#define rsortall(v) sort(rALL(v));

int gcd(int a, int b) {
    while (a != 0 && b != 0)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}

void solve() {
    in(n);
    vector<int> a(n), b(n);
    vector<ll> c(n);
    inv(a); inv(b);

    FOR(i, 0, n) {
        c[i] = (ll)a[i] / gcd(a[i], b[i]) * b[i];
    }

    if (c[0] != a[0] || *(c.end() - 1) != *(b.end() - 1)) {
        cout << "no"; return;
    }

    FOR(i, 1, n) { 
        if (gcd(a[i - 1], c[i]) != a[i]) {
            cout << "no"; return;
        } 
    }
    reverse(ALL(c));
    reverse(ALL(b));
    FOR (i, 1, n) {
        if (gcd(b[i - 1], c[i]) != b[i]) {
            cout << "no"; return;
        } 
    }

    cout << "yes";
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}