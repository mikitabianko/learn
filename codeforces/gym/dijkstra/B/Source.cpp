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

    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);

    int n, m, s, f; cin >> n >> m >> s >> f;
    --s; --f;

    map<int, vector<pair<int, int>>> gr; // from to path

    while (m--) {
        int b, e, w; cin >> b >> e >> w;
        --b;--e;

        gr[b].push_back({e, w});
        gr[e].push_back({b, w});
    }
    
    vector<int> d(n, INF);
    vector<int> c(n, 0);
    d[s] = 0;

    priority_queue<pair<int, int>> q; // -size node
    q.push({0, s});

    while(!q.empty()) {
        auto [ path, v ] = q.top();
        path = -path;
        q.pop();

        if (path > d[v]) continue;

        for (auto& [to, w] : gr[v]) {
            if (w < INF && d[to] > d[v] + w) {
                d[to] = d[v] + w;
                c[to] = v;
                q.push({-d[to], to});
            }
        }
    }

    if (d[f] == INF) {
        cout << -1;
        return 0;
    }
    cout << d[f] << "\n";

    vector<int> path = { f };
    do {
        path.push_back(c[*(path.end() - 1)]);
    } while (*(path.end() - 1) != s);

    for (int i = path.size() - 1; i >= 0; --i) cout << path[i] + 1 << " ";

    return 0;
}