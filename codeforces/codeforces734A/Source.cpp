#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    char c;

    int a = 0, d = 0;

    while(n--) {
        cin >> c;
        if (c == 'A') ++a;
        else ++d;
    }

    if (a > d) cout << "Anton";
    else if (a < d) cout << "Danik";
    else cout << "Friendship";
}