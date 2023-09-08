#include <iostream>
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

void flatten(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* temp;

    while (!st.empty()) {
        temp = st.top();
        st.pop();
        if (temp->right) 
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
        if (!st.empty())
            temp->right = st.top();
        temp->left = nullptr;
    }
}   

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));

    flatten(root);
    
    auto temp = root;

    while (temp) {
        cout << temp->val << ' ';
        temp = temp->right;
    }
}