#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

const int INF = 2009000999;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, m, s; cin >> n >> m >> s;
    map<int, vector<pair<int, int>>> g; // from {to, size}

    while (m--) {
        int a, b, c; cin >> a >> b >> c;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<int> d(n, INF);
    priority_queue<pair<int, int>> q; // { size, node }

    q.push({0, s});
    d[s] = 0;

    while(!q.empty()) {
        auto v = q.top();
        q.pop();

        for (auto& el : g[v.second]) {
            if (el.second < INF && d[el.first] > d[v.second] + el.second) {
                d[el.first] = d[v.second] + el.second;
                q.push({el.second, el.first});
            }
        }
    }

    for (auto& el : d) cout << el << " ";

    return 0;
}