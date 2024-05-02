#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private: 
    int f(vector<int>& arr, int l, int c, int target) {
        if (c == 0) {
            return 0;
        }

        map<int, int> sum;

        int r = arr.size() - c, m;
        do {
            m = (l + r) / 2;

            sum[m] = f(arr, m + 1, c - 1, target - arr[m]);

            if (sum[m] + arr[m] < target) {
                l = m;
            }
            else {
                r = m;
            }
        }  while (l + 1 < r);

        sum[r] = f(arr, r + 1, c - 1, target - arr[r]);

        if (abs(sum[l] + arr[l] - target) < abs(sum[r] + arr[r] - target)) {
            return sum[l] + arr[l];
        }
        else {
            return sum[r] + arr[r];
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return f(nums, 0, 3, target);
    }
};

int main() {
    Solution s;

    vector<int> nums = { -1, 2, 1, -4 };
    // cout << s.threeSumClosest(nums, 1) << '\n';
    // nums = { 0, 0, 0 };
    // cout << s.threeSumClosest(nums, 1) << '\n';
    // nums = { -1000,-5,-5,-5,-5,-5,-5,-1,-1,-1 };
    // cout << s.threeSumClosest(nums, -14) << '\n';
    nums = {  -1,2,1,-4, 4, 1, 7, 8, 4, 3, -10 };
    cout << s.threeSumClosest(nums, -7) << '\n';
    return 0;
}