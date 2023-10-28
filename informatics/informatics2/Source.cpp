#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n), arr2(m);

    for (int& el : arr1) {
        cin >> el;
    }
    for (int& el : arr2) {
        cin >> el;
    }

    for (int& k : arr2) {

        int l = 0, m, r = arr1.size() - 1;

        while (l + 1 < r) {
            m = (l + r) / 2;

            if (arr1[m] < k) {
                l = m;
            }
            else {
                r = m;
            }
        }

        if (k - arr1[l] <= arr1[r] - k) {
            cout << arr1[l] << '\n';
        }
        else {
            cout << arr1[r] << '\n';
        }

    }

    return 0;
}