#include <iostream>
#include <vector>

using namespace std;

vector<int> prefFunc(string& s) {
    vector<int> p(s.length(), 0);
    for (int i = 1; i < p.size(); ++i) {
        int c = p[i - 1];
        while (c > 0 && s[c] != s[i]) c = p[c - 1];

        if (s[i] == s[c]) p[i] = c + 1;
    }
    return p;
}

int main() {
    string str;
    cin >> str;

    for (auto& el : prefFunc(str)) cout << el << ' ';

    return 0;
}