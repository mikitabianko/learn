#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int getMedian(vector<int> a) {
    sort(a.begin(), a.end());
    if (a.size() % 2) return a[a.size() / 2];
    return (a[a.size() / 2] + a[a.size() / 2 + 1]) / 2;
}

unsigned long long dist(int x) {
    unsigned long long ans = 0;
    for (int& el : arr) {
        ans += (unsigned long long)abs(el - x);
    } 
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);

    int n; cin >> n;
    arr.resize(n); 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] -= i;
    }

    int m = getMedian(arr);

    cout << dist(m);
    return 0;
}