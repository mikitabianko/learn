#include <iostream>
#include <vector>

using namespace std;

inline vector<int> pref(string& str) {
    vector<int> p(str.length(), 0);
    for (int i = 1; i < str.length(); ++i) {
        int c = p[i - 1];
        while (c > 0 && str[i] != str[c]) c = p[c - 1];
        if (str[i] == str[c]) p[i] = c + 1;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    string str; cin >> str;

    for (auto& el : pref(str)) {
        cout << el << " ";
    }

    return 0;
}