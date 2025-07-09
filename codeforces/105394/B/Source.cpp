// clang++ -std=c++23 Source.cpp -o Source && ./Source   
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int temp, lwh[3], n, H, i; scanf("%d %d", &n, &H);
    
    unsigned long long ans = 0;

    while (n--) {
        scanf("%d %d %d", &lwh[0], &lwh[1], &lwh[2]);

        temp = 1e9 + 7;
        for (i = 0; i < 3; ++i) {
            if (lwh[i] > H) continue;
            temp = min(temp, min(lwh[(i + 1) % 3], lwh[(i + 2) % 3]));
        }

        if (temp == 1e9 + 7) {
            cout << "impossible";
            return 0;
        }
        ans += temp;
    }

    cout << ans;
    return 0;
}