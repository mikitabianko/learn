#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int findDistance(vector<TreeNode*>& a, vector<TreeNode*>& b) {
        int l = 0, r = min(a.size(), b.size()) - 1, m;

        while (l < r) {
            m = (l + r) / 2;

            if (a[m] == b[m]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        m = (r + l) / 2;

        return a.size() + b.size() - 2  * m;
    }

    void findLeaves(TreeNode* node, vector<TreeNode*> path, unordered_map<TreeNode*, vector<TreeNode*>>& leaves) {
        if (!node) 
            return;

        path.push_back(node);

        if (!node->left && !node->right) {
            leaves[node] = path;
            return;
        }

        findLeaves(node->left, path, leaves);
        findLeaves(node->right, path, leaves);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;

        unordered_map<TreeNode*, vector<TreeNode*>> leaves_mp;
        findLeaves(root, {}, leaves_mp);

        vector<TreeNode*> leaves;
        leaves.reserve(leaves_mp.size());

        for (auto& [key, value] : leaves_mp) {
            leaves.push_back(key);
        }

        for (int i = 0; i < leaves.size(); ++i) {
            for (int j = i + 1; j < leaves.size(); ++j) {
                auto leafI = leaves_mp[leaves[i]];
                auto leafJ = leaves_mp[leaves[j]];
                if (findDistance(leafI, leafJ) <= distance) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution s;

    auto node = 
    // new TreeNode(15, new TreeNode(66, new TreeNode(97, nullptr, 
    //                                                                new TreeNode(54)), 
    //                                               new TreeNode(60, nullptr, 
    //                                                                new TreeNode(49, nullptr, 
    //                                                                                 new TreeNode(90)))), 
                
    //                              new TreeNode(55, new TreeNode(12, nullptr, 
    //                                                                new TreeNode(9)), 
    //                                               new TreeNode(56)));
    
    
    //new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(4)), new TreeNode(3, new TreeNode(4), new TreeNode(4)));

    new TreeNode(1, new TreeNode(1, new TreeNode(1, new TreeNode(1, new TreeNode(4), new TreeNode(5)), nullptr), nullptr), nullptr);

    cout << s.countPairs(node, 3);

    return 0;
}