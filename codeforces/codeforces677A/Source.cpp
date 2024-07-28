#include <iostream>

using namespace std;

int main() {
    int n, h, a, c = 0;
    cin >> n >> h;
    while (n-- && ++c) {
        cin >> a;
        if (a > h)
            ++c;
    }
    cout << c;
}