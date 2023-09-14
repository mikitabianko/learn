#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {

    }

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (!q1.empty()) {
            int temp = q1.front();
            q1.pop();
            return temp;
        }
        return 0;
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return 0;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout << param_2 << ' ' << param_3 << ' ' << param_4;
}