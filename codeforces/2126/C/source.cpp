#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f(int n, int k, vector<int>& arr) {
    int h = arr[k - 1];
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] >= h && arr[i + 1] - arr[i] > h) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n); for (auto& el : arr) cin >> el;

        cout << (f(n, k, arr) ? "yes" : "no") << "\n";
    }

    return 0;
}