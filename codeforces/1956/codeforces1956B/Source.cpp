#include <iostream>
#include <map>

using namespace std;

int main () {

    int t;

    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a;
        map<int, int> mp;

        while (n--) {
            cin >> a;
            ++mp[a];
        }

        int count = 0;

        for (auto& el : mp) {
            if (el.second == 2) {
                ++count;
            }
        }

        cout << count << '\n';
    }

    return 0;
}