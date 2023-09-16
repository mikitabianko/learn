#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    stack<ListNode*> st;
    auto t = head, s = head, f = head->next;

    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }

    auto h2 = s->next;
    s->next = nullptr;
    while (h2) {
        st.push(h2);
        h2 = h2->next;
    }

    while (!st.empty()) {
        auto tmp = t->next;
        t->next = st.top();
        st.pop();
        t = t->next;
        t->next = tmp;
        t = t->next;
    }
}

int main() {
    auto head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    reorderList(head);

    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
}