#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int ans = nums[0] + nums[1] + nums[2], l, r, temp;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                temp = nums[i] + nums[l] + nums[r];
                if (abs(target - temp) < abs(target - ans)) {
                    ans = temp;
                }
                if (temp > target) {
                    --r;
                }
                else if (temp < target) {
                    ++l;
                }
                else {
                    return temp;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = { -1, 2, 1, -4 };
    cout << s.threeSumClosest(nums, 1) << '\n';
    nums = { 0, 0, 0 };
    cout << s.threeSumClosest(nums, 1) << '\n';
    nums = { -1000,-5,-5,-5,-5,-5,-5,-1,-1,-1 };
    cout << s.threeSumClosest(nums, -14) << '\n';

    return 0;
}