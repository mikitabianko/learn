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

    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);

    int n, s, f; cin >> n >> s >> f;
    --s; --f;

    map<int, vector<pair<int, int>>> gr; // from to size

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            int v; cin >> v;
            if (i == j) continue;   
            gr[i].push_back({j, (v == -1 ? INF : v)});
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

        for (auto& [ to, w ] : gr[v]) {
            if (w < INF && d[to] > d[v] + w) {
                d[to] = d[v] + w;
                q.push({-d[to], to});
            }
        }
    }

    cout << (d[f] == INF ? - 1: d[f]);

    return 0;
}