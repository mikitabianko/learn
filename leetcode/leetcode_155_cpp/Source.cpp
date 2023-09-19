#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
private:
    vector<int> minArr;
    vector<int> st;
    int ind;
public:
    MinStack() {
        ind = -1;
    }

    void push(int val) {
        ++ind;
        if (st.size() <= ind) {
            st.resize(ind + 1);
            minArr.resize(ind + 1);
        }
        st[ind] = val;
        minArr[ind] = ind == 0 ? val : min(minArr[ind - 1], val);
    }

    void pop() {
        --ind;
        if (ind * 4 <= st.size()) {
            st.resize(2 * ind);
            st.reserve(2 * ind);
        }
    }

    int top() {
        return st[ind];
    }

    int getMin() {
        return minArr[ind];
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(5);
    obj->push(2);
    obj->push(3);
    obj->push(1);
    obj->push(5);
    obj->push(5);
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout << param_3 << ' ' << param_4;
}