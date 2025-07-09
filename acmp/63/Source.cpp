#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    for (int i = 1; i * i <= m; ++i) {
        if (m % i == 0 && i + (m / i) == n) {
            cout << min(i, m / i) << ' ' << max(i, m / i);
            return 0;
        }
    }

    return 0;
}