#include <iostream>
#include <vector>
#include <map>

using namespace std;

int arr[4] = {1, 0, -1, 0};

struct Wave {
    int p, l;
    long long a;
    Wave(int p, int l, long long a) : p(p), l(l), a(a) {}
    Wave() {}

    inline long long calc(int x) {
        if (x < p || x > p + l) return 0;
        return a * arr[(x - p) % 4];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, w; cin >> n >> w;

    vector<Wave> ws;
    ws.reserve(n);

    while (n--) {
        char c; cin >> c;

        if (c == '!') {
            int p, l, a; cin >> p >> l >> a;
            ws.push_back(Wave(p, l - 1, a)); 
        } else {
            int x; 
            long long ans = 0; cin >> x;
            for (auto& el : ws) {
                ans += el.calc(x);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}