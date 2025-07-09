#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> f(vector<int>& arr) {
    vector<int> d(arr.size() + 1,  0);
    for (auto& el : arr) ++d[el];

    int mex = 0;
    for (; d[mex]; ++mex);

    vector<int> ans(arr.size() + 1, 0);

    for (int k = 0; k < arr.size() - mex + 1; ++k) 
        for (int i = 0; i <= mex; ++i) 
            if (d[i] <= k) ++ans[k];

    for (int i = 1; i <= mex; ++i)
        ans[(int)ans.size() - i] = i;

    return ans; 
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> arr(n); 
        for (auto& el : arr) cin >> el;

        for (auto& el : f(arr)) cout << el << " ";
        cout << "\n";
    }

    return 0;
}