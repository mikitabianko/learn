#include <iostream>

using namespace std;

int main() {

    int n; cin >> n;

    int l = 1, r = n;

    while (l + 1 < r) {
        int m = (l + r) / 2;
        cout << "? " << m << "\n"; 
        fflush(stdout);
        string str; cin >> str;
        if (str == "lion") {
            l = m;
        } else {
            r = m;
        }
    }

    cout << "! " << l;

    return 0;
}