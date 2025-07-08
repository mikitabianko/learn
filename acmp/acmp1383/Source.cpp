#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
  int n, m, s;

  const int INF = 2009000999;

  cin >> n >> m >> s;

  map<int, set<pair<int, int>>> graph; // <node, size>

  for (int i = 0; i < m; ++i) {
    int a, b, size;
    cin >> a >> b >> size;

    graph[a].insert(make_pair(b, size));
    graph[b].insert(make_pair(a, size));
  }

  vector<int> d(n, INF);
  
  d[s] = 0;

  priority_queue<pair<int, int>> q; // size, node
  
  q.push(make_pair(0, s));

  while (q.empty() == false) {
    int v = q.top().second;
    int size = -q.top().first;
    q.pop();
    
    if (size > d[v])
      continue;

    for (const auto& [first, sec] : graph[v]) {
      if (sec < INF && d[first] > sec + d[v]) {
        d[first] = sec + d[v];
        q.push(make_pair(-d[first], first));
      }
    }
  }

  for (int& el : d) {
    cout << el << " ";
  }

  return 0;
}
