#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {}

    void push(int x) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(x);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        int tmp = st1.top();
        st1.pop();
        return tmp;
    }

    int peek() {
        return st1.top();
    }

    bool empty() {
        return st1.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(5);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    cout << param_2 << ' ';
    cout << param_3 << ' ';
    cout << param_4 << ' ';
}