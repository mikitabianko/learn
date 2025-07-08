#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool f(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i + 1] < arr[i] * 2 && arr[i + 1] * 2 > arr[i]) {
            return true;
        }
    }
    return false;
}

int main() {

    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n);

        for (auto& el : arr) {
            cin >> el;
        }

        if (f(arr)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}