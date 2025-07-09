#include <iostream>

using namespace std;

int main() {

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        int temp = 1, i = 0;
        for (; i < (n + 1) / 2; ++i, temp += 2) {
            cout << temp << " ";
        }
        if (n % 2) temp -= 3;
        else --temp;
        for (; i < n; ++i) {
            cout << temp << " ";
            temp -= 2;
        }
        cout << "\n";
    }

    return 0;
}