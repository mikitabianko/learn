#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int y) {
    return ((y % 400) == 0 || ((y % 4) == 0 && (y % 100)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int a, b; cin >> a >> b;
    int c, d, e; cin >> c >> d >> e;

    int ms[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> p(13, 0); 
    for (int i = 1; i < 13; ++i) p[i] += p[i - 1] + ms[i];

    int today = p[d - 1] + c;
    if (check(e) && d > 2) ++today;

    int y = e;
    if (b < d || (b == d && a < c)) ++y;
    if (a == 29 && b == 2) while (!check(y)) ++y;

    int bd = p[b - 1] + a;
    if (check(y) && b > 2) ++bd;

    for (int i = e; i < y; ++i) {
        bd += p[12] + check(i);
    }

    cout << bd -  today;

    return 0;
}