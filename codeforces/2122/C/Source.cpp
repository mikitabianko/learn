// g++ -std=c++23 Source.cpp -DLOCAL && ./a.out && rm ./a.out  
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>

#ifndef LOCAL
#include <bits/stdc++.h>
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define vec vector

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

void solve() {
    in(n);

    vec<int> x(n), y(n), c(n);
    FOR(i, 0, n) cin >> x[i] >> y[i];
    iota(ALL(c), 0);

    sort(ALL(c), [&](int i, int j) {
        return x[i] < x[j];
    });
    sort(c.begin(), c.begin() + n / 2, [&](int i, int j) {
        return y[i] < y[j];
    });
    sort(c.begin() + n / 2, c.end(), [&](int i, int j) {
        return y[i] < y[j];
    });

    FOR(i, 0, n / 2) 
        cout << 1 + c[i] << " " << 1 + c[n - i - 1] << "\n";
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