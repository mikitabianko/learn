#include <iostream>
#include <algorithm>

using namespace std;

long long f(long long n) {
    if (n <= 1) {
        return n;
    }
    long long l = 0, r = min((long long)2e9, n), m;

    while (l + 1 < r) {
        m = (l + r) / 2;

        if (m * m < n) {
            l = m;
        }
        else if (m * m > n){
            r = m;
        }
        else {
            break;
        }
    }

    return (l + r) / 2;
}

int main() {

    long long a, b, c, d;

    cin >> a >> b >> c >> d;

    a = (min(a, b) / 2) * 2 + (min(c, d) / 2) * 2;

    cout << f(a);

    return 0;
}