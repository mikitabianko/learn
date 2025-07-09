#include <iostream>
#include <queue>
#include <vector>

using namespace std;

inline vector<int> bfs(vector<vector<int>> &g, int n, int s, int f) {
  queue<int> q;
  vector<int> p(n, -1); // path
  p[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int i = 0; i < n; ++i) {
      if (p[i] == -1 && g[v][i]) {
        q.push(i);
        p[i] = v;
      }
    }
  }
  return p;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;

  vector<vector<int>> g(n, vector<int>(n));

  for (auto &a : g)
    for (auto &b : a)
      cin >> b;

  int s, f;
  cin >> s >> f;
  --s;
  --f;

  auto p = bfs(g, n, s, f);

  if (p[f] == -1) {
    cout << -1;
    return 0;
  }

  vector<int> path;
  path.push_back(f);

  while (*(path.end() - 1) != s) {
    path.push_back(p[*(path.end() - 1)]);
  }

  cout << path.size() - 1 << "\n";

  for (int i = path.size() - 1; path.size() > 1 && i >= 0; --i) {
    cout << path[i] + 1 << " ";
  }

  return 0;
}
