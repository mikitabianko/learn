#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int ans = 0, temp, i = 0;

    while (!st.empty() || i < heights.size()) {
        if (i < heights.size() && (st.empty() || heights[st.top()] <= heights[i])) {
            st.push(i++);
        }
        else {
            temp = st.top();
            st.pop();
            ans = max(ans, heights[temp] * (st.empty() ? i : i - st.top() - 1));
        }
    }

    return ans;
}

int main() {
    vector<int> heights = { 2,1,5,6,2,3 };
    cout << largestRectangleArea(heights);
}