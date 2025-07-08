#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

		if (n % 4) cout << "Alice\n";
		else cout << "Bob\n";
    }    

	return 0;
}