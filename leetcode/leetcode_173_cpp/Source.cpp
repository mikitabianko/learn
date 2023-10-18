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

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* root) {
        auto tmp = root;

        while (tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        auto tmp = st.top();
        st.pop();
        pushLeft(tmp->right);
        return tmp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    auto root = new TreeNode(7, new TreeNode(3, new TreeNode(2), nullptr), new TreeNode(15, new TreeNode(9), new TreeNode(20)));

    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
    
    cout << param_1 << ' ' << param_2;
}