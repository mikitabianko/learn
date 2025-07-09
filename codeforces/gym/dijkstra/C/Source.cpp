#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);

    int n, m, s; cin >> n >> m >> s;
    --s;

    map<int, vector<pair<int, int>>> g; // from to size

    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        g[a].push_back({b, c});
    }

    vector<int> d(n, INF);
    d[s] = 0;

    priority_queue<pair<int, int>> q; // size node
    q.push({0, s});
 
    while (!q.empty()) {
        auto [ path, v ] = q.top();
        path = -path;
        q.pop();

        if (path > d[v]) continue;

        for (auto& [to, w] : g[v]) {
            if (w < INF && d[to] > d[v] + w) {
                d[to] = d[v] + w;
                q.push({-d[to], to});
            }
        }
    }

    for (auto& el : d) {
        cout << el << "\n";
    }

    return 0;
}