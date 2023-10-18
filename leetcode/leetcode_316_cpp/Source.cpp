#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> mp;
        map<char, bool> use;
        stack<char> st;

        for (auto& el : s) {
            ++mp[el];
        }

        for (auto& el : s) {
            --mp[el];
            if (!use[el]) {
                while (!st.empty() && st.top() > el && mp[st.top()] > 0) {
                    use[st.top()] = false;
                    st.pop();   
                }
                use[el] = true;
                st.push(el);
            } 
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution s;

    cout << s.removeDuplicateLetters("ksdjhfasdhfksjdhfklsdhflkjsahd") << '\n';   // adfhkljs
    cout << s.removeDuplicateLetters("bcabc") << '\n';      // abc
    cout << s.removeDuplicateLetters("cbacdcbc") << '\n';   // acdb
    cout << s.removeDuplicateLetters("mnvnmmvb") << '\n';   // mnvb

    return 0;
}