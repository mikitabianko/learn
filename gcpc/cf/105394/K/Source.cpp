#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    string s, t; cin >> s >> t;
    map<char, int> e;
    for (auto& el : t) {
        e[el]++;
    }

    map<char, map<char, char>> d = {
        { 'v', {{'b', 'p'}, {'d', 'q'}, {'p', 'b'}, {'q', 'd'}}}, 
        { 'h', {{'b', 'd'}, {'d', 'b'}, {'p', 'q'}, {'q', 'p'}}},
    };

    if (e['h'] % 2) {
        reverse(s.begin(), s.end());
        for (auto& a : s) {
            a = d['h'][a];
        }
    }
    if (e['r'] % 2) {
        reverse(s.begin(), s.end());
        for (auto& a : s) {
            a = d['v'][a];
            a = d['h'][a];
        }
    }
    if (e['v'] % 2) {
        for (auto& a : s) {
            a = d['v'][a];
        }
    }

    cout << s;

    return 0;
}