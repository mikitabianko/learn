#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto f = [&](int n) {
        string s(sizeof(n) * 8, '0');
        for (int i = 0; i < s.length(); ++i) {
            s[s.length() - i - 1] = '0' + ((n >> i) & 1);
        }
        return s;
    };

    int a = 100;

    for (int i = 0; i <= a; ++i)
        cout << f(i) << "\n";

    return 0;
}