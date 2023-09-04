#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s) {
    stack<pair<char, int>> st;
    for (int i = 0; i < s.length(); ++i)
        if (st.empty())
            st.push({ s[i], i + 1 });
        else if (st.top().first == '(' && s[i] == ')')
            st.pop();
        else
            st.push({ s[i], i + 1 });

    int ans = 0, temp = s.length();
    while (!st.empty()) {
        ans = max(ans, temp - st.top().second);
        temp = st.top().second - 1;
        st.pop();
    }

    return max(ans, temp);
}

int main() {
    cout << longestValidParentheses("((()))()((()()((())))))");
}