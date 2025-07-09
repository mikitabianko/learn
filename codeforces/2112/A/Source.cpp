// clang++ -std=c++23 Source.cpp && ./a.out && rm -rf ./a.out
#include <iostream>
#include <algorithm>

using namespace std;

bool f(int a, int x, int y) {   
    if ((a < x && a < y) || (a > x && a > y)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);

    int t; cin >> t;

    while (t--) {
        int a, x, y; cin >> a >> x >> y;

        cout << (f(a, x, y) ? "YES\n" : "NO\n");
    }


    return 0;
}