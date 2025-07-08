#include <iostream>
#include <vector>

using namespace std;

vector<int> prefFunc(string s) {
    vector<int> p(s.size(), 0);
    for (int i = 1; i < p.size(); ++i) {
        int c = p[i - 1];

        while (c > 0 && s[i] != s[c]) c = p[c - 1];

        if (s[i] == s[c]) p[i] = c + 1;
    }
    return p;
}

int main() {

    string s, t; cin >> s >> t;

    auto arr = prefFunc(t + "#" + s);

    for (int i = t.length() + 1; i < arr.size(); ++i) {
        if (arr[i] == t.length()) cout << i - 2 * t.length() << ' ';
    }

    return 0;
}
