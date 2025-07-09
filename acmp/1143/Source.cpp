#include <iostream>

using namespace std;

int main() {
    int count = 0, p = 1e9, pp = 1e9, a = 1e9;
    do {
        if (pp < p && p > a)
            ++count;
        pp = p;
        p = a;
        cin >> a;
    } while (a);
    cout << count;
}