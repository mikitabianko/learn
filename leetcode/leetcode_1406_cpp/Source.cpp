#include <iostream> 
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
    map<pair<int, int>, int> mp;

    void f(vector<int>& arr, int ind, int p) {        
        if (ind >= arr.size()) {
            return;
        }

        int sum = 0;
        for (int i = ind; i < ind + 3 && i < arr.size(); ++i) {
            sum += arr[i];
            mp[{ind, p}] = max(sum, mp[{ind, p}]);
            for (int j = 1; j <= 3; ++j) {
                mp[{ind, p}] = max(mp[{ind - j, p}] + sum, mp[{ind, p}]);
            }

            f(arr, i + 1, (p + 1) % 2);
        }
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        f(stoneValue, 0, 0);

        for (auto& el : mp) {
            cout << el.first.first << el.first.second << ' ' << el.second << "\n";
        }

        return "hui";
    }
};

int main() {

    Solution s;

    // vector<int> data = { 1,2,3,7 };
    vector<int> data = { 1,2,3,-9 };
    // vector<int> data = { 1,2,3,7 };

    cout << s.stoneGameIII(data);

}
