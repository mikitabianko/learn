#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);


    long long m = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, a[i]);
    }

    cout << m * m * m << endl;
    return 0;
}