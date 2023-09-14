#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    if (!root)
        return {};
    stack<TreeNode*> st;
    TreeNode* temp;
    vector<int> ans;

    st.push(root);
    while (!st.empty()) {
        temp = st.top();
        st.pop();
        if (temp->left) {
            st.push(temp->left);
        }
        if (temp->right) {
            st.push(temp->right);
        }
        ans.push_back(temp->val);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    auto root = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(8), nullptr), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));

    for (auto& el : postorderTraversal(root)) {
        cout << el << ' ';
    }
}