// g++ -std=c++23 Source.cpp -DLOCAL && ./a.out && rm ./a.out  
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

    ull ans = 0;
    FOR(i, 0, n) {
        in(a);in(b);in(c);in(d);
        ans += max((ll)0, (ll)a - c);
        if (b > d) {
            ans += (ll)(b - d + min(a, c));
        }
    }

    cout << ans;
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