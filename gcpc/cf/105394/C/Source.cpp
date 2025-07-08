// clang++ -std=c++23 Source.cpp -o Source && ./Source 
#include <iostream>
#include <vector>
#include <map>

using namespace std;

inline bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

inline bool isVar(string& str) {
    return str.length() == 1 && isLetter(str[0]);
}

inline bool areEqual(string& a, string& b, int c, int d, int e) {
    //cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
    if (isVar(a) && isVar(b)) {
        if (c == d) return true;
        if (c > e) return d == 0;
        return false;
    }
    return a == b;
}

inline void postDist(vector<string>::iterator l, vector<string>::iterator r, vector<int>::iterator it) {
    map<string, int> d;
    for (--r; r >= l; --r, --it) {
        int dist = -1;
        if (isVar(*r)) {
            if (d.count(*r)) dist = d[*r] - (r - l);
            else dist = 0;
            d[*r] = r - l;
        }
        *it = dist;
    }
}

inline bool f(vector<string>& arr, vector<int>& vr, int n) {
    vector<int> p(arr.size(), 0);
    for (int i = 1; i < arr.size(); ++i) {
        int c = p[i - 1];
        while (c > 0 && !areEqual(arr[i], arr[c], vr[i], vr[c], n - c - 1)) {
            c = p[c - 1];
        }

        if (areEqual(arr[i], arr[c], vr[i], vr[c], n - c - 1)) p[i] = c + 1;

        if (p[i] == n) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, q; cin >> n;
    vector<string> r(n);
    for (auto& token : r) cin >> token;
    cin >> q;

    while (q--) {
        int m; cin >> m;
        vector<string> qr(n + m + 1);
        vector<int> vr(n + m + 1, -1);
        for (int i = 0; i < m; ++i) cin >> qr[i];
        qr[m] = "#";
        for (int i = 0; i < n; ++i) qr[i + m + 1] = r[i];

        postDist(r.begin(), r.end(), vr.end() - 1);
        postDist(qr.begin(), qr.begin() + m, vr.begin() + m - 1);

        cout << (f(qr, vr, m) ? "yes\n" : "no\n");
    }

    return 0;
}