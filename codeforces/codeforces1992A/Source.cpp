#include <iostream>
#include <algorithm>

using namespace std;

int& m(int& a, int&b) {
    return (a > b ? b : a);
}

int main() {

    int t;
    int a, b, c;

    cin >> t; 

    while (t--) {

        cin >> a >> b >> c;

        for (int i = 0; i < 5; ++i) {
            ++m(m(a, b), c);
        }

        cout << a * b * c << '\n';
    }
}