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
 

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;

    st.push(root);

    while (!st.empty()) {
        while (st.top() != nullptr)
            st.push(st.top()->left);
            
        st.pop();
        if (st.empty())
            break;
        auto temp = st.top();
        ans.push_back(temp->val);
        st.pop();
        st.push(temp->right);
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    for (auto& el : inorderTraversal(root))
        cout << el << ' ';
}