#include <iostream> // radix sort O(n) karl!!!
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) { // max pow is 9
        vector<vector<int>> buckets(10);
        int pow = 1;
        for (int p = 0; p < 10; ++p) {
            for (int el : nums) {
                buckets[(el / pow) % 10].push_back(el);
            }
            int it = 0;
            for (int i = 0; i < 10; ++i) {
                for (int el : buckets[i]) {
                    nums[it++] = el;
                }
                buckets[i].clear();
            }
            if (p != 9) pow *= 10;
        }

        int ans = 0;

        for (int i = 1; i < nums.size(); ++i) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> nums = {3,6,9,1000000000};

    cout << s.maximumGap(nums) << '\n';

    return 0;
}