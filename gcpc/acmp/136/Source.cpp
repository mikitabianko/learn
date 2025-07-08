#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, m = -1; cin >> n;

    vector<vector<int>> g(n, vector<int>(n, INF));

    for (auto& a : g) for (auto& b : a) cin >> b;
    for (auto& a : g) for (auto& b : a) b = (b == -1 ? INF : b);

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    for (auto& a : g) for (auto& b : a) m = max(m, (b == INF ? -1 : b));

    cout << m;

    return 0;
}