#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int num = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }
            if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' || i == s.length() - 1) {
                if (sign == '+') {
                    st.push(num);
                }
                if (sign == '-') {
                    st.push(-num);
                }
                if (sign == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                if (sign == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                sign = s[i];
                num = 0;
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {

    Solution s;

    cout << s.calculate("2+2*2") << '\n';       // 6
    cout << s.calculate("3+2*2") << '\n';       // 7
    cout << s.calculate(" 3/2 ") << '\n';       // 1
    cout << s.calculate(" 3+5 / 2 ") << '\n';   // 5
    cout << s.calculate("2147483647 ") << '\n'; // 2147483647

	return 0;
}