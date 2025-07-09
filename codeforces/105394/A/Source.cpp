// clang++ -std=c++20 Source.cpp -o Source && ./Source 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
 
map<int, int> mem;
map<int, bool> visited;
 
int longestPath(map<int, vector<int>>& gr, int v) {
    if (visited[v]) {
        return mem[v] ? mem[v] : 0;
    }
 
    int m = 1;
    visited[v] = true;
 
    for (int& node : gr[v]) {
        m += longestPath(gr, node);
    }
    return m;
}
 
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n, m, i, j; cin >> n >> m;
 
    map<int, vector<int>> gr;
 
    while (m--) {
        cin >> i >> j;
        gr[i].push_back(j);
        gr[j].push_back(i);
    }
 
    int path = 0;
 
    for (int i = 1; i <= n; ++i) {
        path = max(path, longestPath(gr, i));
    }
 
    cout << path;
 
    return 0;
}
 
// 5 3
// 1 2
// 2 3
// 4 5
 
// 3