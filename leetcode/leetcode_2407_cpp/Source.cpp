#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

struct Node {
    int Count;
    int Min;
    int Max;
    int End;
};

class Solution {
private:
    Node* tree;

    void build(vector<int>& nums, int tl, int tr, int v) {
        if (tl == tr) {
            tree[v] = Node{1, nums[tl], nums[tl], nums[tl]};
            return;
        }

        int m = (tl + tr) / 2;

        build(nums, tl, m, 2 * v);
        build(nums, m + 1, tr, 2 * v + 1);

        tree[v] = Node{ max(tree[2 * v].Count, tree[2 * v + 1].Count), 
                        min(tree[2 * v].Min, tree[2 * v + 1].Min), 
                        max(tree[2 * v].Max, tree[2 * v + 1].Max), 
                        min(tree[2 * v].End, tree[2 * v + 1].End)};
    }

    void upd(int tl, int tr, int v, int ind, int value) {
        // на листике все есть, чтобы тебе вспомнить, что нужно здесь написать
    }

    int get(int tl, int tr, int v, int ql, int qr, int k) {

        return -1;
    }
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        tree = new Node[2 * nums.size() + 1];

        build(nums, 0, nums.size() - 1, 1);

        for (int i = 0; i < nums.size(); ++i) {
            int count = get(0, nums.size() - 1, 1, 0, i, k);
            upd(0, nums.size() - 1, 1, i, count);
        }

        int ans = tree[1].Count;

        delete tree;
        return ans;
    }
};

int main() {

    Solution s;

    vector<int> a = {4,2,1,4,3,4,5,8};

    cout << s.lengthOfLIS(a, 3);

    return 0;
}