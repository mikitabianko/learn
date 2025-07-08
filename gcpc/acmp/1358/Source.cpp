#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {

    int n, m; cin >> n >> m;
    map<int, int> gr;
    set<pair<int, int>> s;

    while(m--) {
        int u, v; cin >> u >> v;

        s.insert({u, v});
    }
    
    for (auto& el : s) {
        gr[el.first]++;
        gr[el.second]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (gr[i] < n - 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}