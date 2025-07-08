#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n; cin >> n;

    vector<vector<int>> g(n, vector<int>(n, INF));

    for (auto& line : g) for (auto& el : line) cin >> el;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) 
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    for (auto& line : g) {
        for (auto& el : line) cout << el << " ";
        cout << "\n";
    }

    return 0;
}