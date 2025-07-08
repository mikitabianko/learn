#include <iostream>
#include <vector>

using namespace std;

bool f(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size();) {
        if (arr[i] == 1) {
            if (x == -1) return false;
            i += x;
            x = -1;
        } else ++i;
    }
    return true;
}

int main() {
    
    int t; cin >> t;

    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> arr(n); for (auto& el : arr) cin >> el;
        cout << (f(arr, x) ? "yes\n" : "no\n");
    }

    return 0;
}