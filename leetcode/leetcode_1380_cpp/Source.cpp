#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); ++i) {
            int minId = 0;

            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][minId] > matrix[i][j]) {
                    minId = j;
                }
            }

            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[j][minId] > matrix[i][minId]) {
                    minId = -1;
                    break;
                }
            }
            if (minId != -1)
                ans.push_back(matrix[i][minId]);
        }
        return ans;
    }
};

int main() {

    Solution s;

    auto mat = vector<vector<int>>{{3, 7, 8}, 
                                    {9, 11, 13}, 
                                    {15, 16, 17}};

    for (auto& el : s.luckyNumbers(mat)) {
        cout << el << ' ';
    }

    return 0;
}