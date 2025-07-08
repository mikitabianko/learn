#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    string s, t; cin >> s >> t;
    map<char, int> hvr;
    for (auto& el : t) hvr[el]++;

    if (hvr['r'] % 2) {
        ++hvr['h'];
        ++hvr['v'];
    }
    if (hvr['h'] % 2) {
        reverse(s.begin(), s.end());
        for (auto& el : s) {
            if (el == 'b') el = 'd';
            else if (el == 'd') el = 'b';
            else if (el == 'q') el = 'p';
            else if (el == 'p') el = 'q';
        }
    }
    if (hvr['v'] % 2) {
        for (auto& el : s) {
            if (el == 'b') el = 'p';
            else if (el == 'd') el = 'q';
            else if (el == 'q') el = 'd';
            else if (el == 'p') el = 'b';
        }
    }

    cout << s;

	return 0;
}