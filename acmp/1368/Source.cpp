#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, s, t; cin >> n >> s >> t;

    vector<vector<int>> d(n, vector<int>(n));

    for (auto& a : d) for (auto& b : a) cin >> b;
    for (auto& a : d) for (auto& b : a) b = (b == -1 ? INF : b);

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int ans = d[s - 1][t - 1];
    cout << (ans == INF ? -1 : ans);

    return 0;
}