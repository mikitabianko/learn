#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int num = 0;
        int sign = 1;
        int* arr = new int[75000];
        int ind = 0;
        arr[0] = 1;
        for (char& c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            }
            else if (c == '(') {
                arr[++ind] = sign;
            }
            else if (c == ')') {
                --ind;
            }
            else if (c == '+' || c == '-') {
                ans += sign * num;
                sign = (c == '+' ? 1 : -1) * arr[ind];
                num = 0;
            }
        }
        return ans + sign * num;
    }
};

int main() {
    auto solution = new Solution();

    cout << solution->calculate("1 + 1") << '\n'; // 2
    cout << solution->calculate(" 2-1 + 2 ") << '\n'; // 3
    cout << solution->calculate("(1+(4+5+2)-3)+(6+8)") << '\n'; // 23
    cout << solution->calculate("1 + 1 -5 + 23 - (5 + 3)") << '\n'; // 12
    cout << solution->calculate("1-(     -2)") << '\n'; // 3
}