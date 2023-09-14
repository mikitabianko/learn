#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> ans;

    TreeNode* temp;

    st.push(root);

    while (!st.empty()) {
        temp = st.top();
        st.pop();
        if (temp->right) {
            st.push(temp->right);
        }
        if (temp->left) {
            st.push(temp->left);
        }
        ans.push_back(temp->val);
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr));

    for (auto& el : preorderTraversal(root)) {
        cout << el << ' ';
    }
}