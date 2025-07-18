#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Casino {
    int l, r, real;
};

bool compare(Casino& a, Casino& b) {
    return a.real < b.real;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    int t; cin >> t;

    while(t--) {
        int n, x; cin >> n >> x;

        vector<Casino> arr(n); for (auto& el : arr) cin >> el.l >> el.r >> el.real;

        sort(arr.begin(), arr.end(), compare);

        int ans = x;

        for (auto& el : arr) 
            if (ans < el.real && ans >= el.l && ans <= el.r) ans = el.real;

        // for (auto& el : arr) 
        //     cout << el.l << " " << el.r << " " << el.real << "\n";
        
        cout << ans << "\n";
    }

    return 0;
}