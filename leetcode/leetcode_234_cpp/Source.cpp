#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> stack;
        auto tmp = head;

        while (tmp) {
            stack.push(tmp);
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp) {
            if (tmp->val != stack.top()->val) {
                return false;
            }
            tmp = tmp->next;
            stack.pop();
        }
        return true;
    }
};

int main() {
    auto head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    auto solution = new Solution();

    cout << solution->isPalindrome(head);
}