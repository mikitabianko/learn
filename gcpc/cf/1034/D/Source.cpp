#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
		string str; cin >> str;

		int count = 0;
		for (auto& el : str) {
			if (el == '1') count++;
		}
		if (count <= k) cout << "Alice\n";
		else if (n >= k * 2) cout << "Bob\n";
		else cout << "Alice\n";
        
    }    

	return 0;
}