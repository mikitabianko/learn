//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<int, int> t, add;

inline int getV(int v) {
    return add[v] + t[v];
}

inline int get(int tl, int tr, int v, int ql, int qr) {
    if (ql > qr) {
        return 1e9 + 7;
    }
    if (ql == tl && qr == tr) {
        return getV(v);
    }
    int m = (tl + tr) / 2;

    return min(get(tl, m, 2 * v, ql, min(qr, m)), get(m + 1, tr, 2 * v + 1, max(ql, m + 1), qr)) + add[v];
}

inline void push(int v) {
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    add[v] = 0;
}

inline void upd(int tl, int tr, int v, int ul, int ur, int val) {
    if (ul > ur) {
        return;
    }
    if (ul == tl && ur == tr) {
        add[v] += val;
        return;
    }

    push(v);
    int m = (tl + tr) / 2;

    upd(tl, m, 2 * v, ul, min(m, ur), val);
    upd(m + 1, tr, 2 * v + 1, max(m + 1, ul), ur, val);

    t[v] = min(getV(v * 2), getV(v * 2 + 1));
}

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;
	map<int, map<int, int>> w;

	int maxW = 0;

    while (m--) {
        int i, d, c; cin >> i >> d >> c;
        if (w[i][-c]) w[i][-c] = min(w[i][-c], d);
        else w[i][-c] = d;
		maxW = max(maxW, c);
    }
    ++maxW;
    int size = maxW;

	for (int i = 1; i < n; ++i) {
        if (!w.count(i)) {
            maxW = -1;
            break;
        }

        int l = 1;
        pair<int, int> temp = *w[i].begin();
        map<int, int> mp;
        for (auto& el2 : w[i]) {
            if (el2.second < temp.second) temp = el2;
            mp[-temp.first] = temp.second;
        }

		for (auto& el : mp) {
			if (el.first > maxW) {
                upd(1, size, 1, l, maxW, el.second);
                l = maxW;
                break;
            }
			upd(1, size, 1, l, el.first, el.second);
            l = el.first + 1;
		}
		maxW = min(l, maxW);
    }

    int q; cin >> q;

    while (q--) {
        int w; cin >> w;
		if (w >= maxW) {
			cout << "impossible\n";
			continue;
		}
		cout << get(1, size, 1, w, maxW - 1) << "\n";
    }
	return 0;
}
