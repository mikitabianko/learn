#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m; 
    cin >> n >> m;

    vector<bool> prims(m + 1, true);

    for (int i = 2; i * i <= m; ++i) {
        if (prims[i]) {
            for (int j = i * i; j <= m; j += i) {
                prims[j] = false;
            }
        }
    }

    int count = 0;

    for (int i = n; i <= m; ++i) {
        if (prims[i]) {
            count = 1;
            cout << i << "\n";
        }
    }

    if (count == 0) {
        cout << "Absent";
    }

    return 0;
}

// 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 1 1 0 1 0 1 0 0 0  1  0  1  0  0