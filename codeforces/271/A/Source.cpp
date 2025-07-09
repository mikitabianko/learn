#include <iostream>

using namespace std;

bool check(int n) {
    int a[4];

    for (int i = 0; i < 4; ++i) {
        a[i] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (a[i] == a[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int n; cin >> n;

    for (n+= 1; n < 10000; ++n) {
        if (check(n)) {
            break;
        }
    }

    cout << n;

    return 0;
}