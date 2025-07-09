#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(vector<int>& arr, int a, int l, int r) {
    while (l < r) {
        int m = (l + r) / 2;

        if (arr[m] >= a) 
            r = m;
        else 
            l = m + 1;
    }
    int m = (r + l) / 2;
    return m;
}

long long f(vector<int>& arr) {
    long long ans = 0;
    int blue = *(arr.end() - 1);

    for (int i = 0; i < (int)arr.size() - 2; ++i) {
        for (int j = i + 1; j < (int)arr.size() - 1; ++j) {
            int right = binSearch(arr, arr[i] + arr[j], j + 1, arr.size());
            int left = binSearch(arr, blue - arr[i] - arr[j] + 1, j + 1 , arr.size());

            ans += max(0LL, (long long)right - left);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> arr(n);
        for (auto& el : arr) cin >> el;

        cout << f(arr) << "\n";
    }

    return 0;
}