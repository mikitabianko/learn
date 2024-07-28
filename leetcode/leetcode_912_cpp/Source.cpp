#include <iostream> // radix sort
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<vector<int>> buckets(2);
        int maxPow = sizeof(nums[0]) * 8;
        for (int& el : nums) { // to uint
            el ^= 1 << (maxPow - 1);
        }
        for (int p = 0; p < maxPow; ++p) {
            for (int el : nums) {
                buckets[!!(el & (1 << p))].push_back(el);
            }
            int it = 0;
            for (int i = 0; i < 2; ++i) {
                for (int el : buckets[i]) {
                    nums[it++] = el;
                }
                buckets[i].clear();
            }
        }
        for (int& el : nums) { // to uint
            el ^= 1 << (maxPow - 1);
        }
        return nums;
    }
};

int main() {

    Solution s;

    vector<int> nums = {3,-1};

    for (int el : s.sortArray(nums)) {
        cout << el << ' ';
    }

    return 0;
}