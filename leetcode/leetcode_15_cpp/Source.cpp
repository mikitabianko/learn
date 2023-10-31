#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> ht;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ht.insert({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    continue;
                }
                if (sum > 0) {
                    --r;
                }
                else {
                    ++l;
                }
            }
        }

        vector<vector<int>> ans;
        ans.reserve(ht.size());

        for (auto& el : ht) {
            ans.push_back(el);
        }

        return ans;
    }
};

int main() {

    Solution solution;

    vector<int> nums = { -1,0,1,2,-1,-4 };

    for (auto& list : solution.threeSum(nums)) {
        for (int& el : list) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}