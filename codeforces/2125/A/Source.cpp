// g++ -std=c++23 Source.cpp -DLOCAL && ./a.out && rm ./a.out  
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void solve() {
	string s; cin >> s;
	map<char, int> m;
	for(auto& el : s) {
		m[el]++;
	}
	while(m['T'] > 0) {
		cout << 'T';
		m['T']--;
	}

	for (char i = 'A'; i <= 'Z'; ++i) {
		for (int j = 0; j < m[i]; ++j) {
			cout << i;
		}
	}
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    cin.tie(0)->sync_with_stdio(0); 

    int tt; cin >> tt;

    while (tt--) {
        solve();
        cout << "\n";
    }

    return 0;
}