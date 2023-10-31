#include <iostream>
 
using namespace std;
 
int main() {
 
    int n, m;
 
    cin >> n >> m;
 
    if (m == 0) {
        cout << 1;
        return 0;
    }
    if (m == 1) {
        cout << n;
        return 0;
    }
 
    int i = (n - m) / (m - 1);
    cout << (2 * (n - m + 1) - (m - 1) * i) / 2 * (i + 1);
 
    return 0;
}