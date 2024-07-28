#include <iostream>

using namespace std;

class Solution {
public:
    // double myPow(double x, int n) { // 1
    //     if (n == 0) {
    //         return 1;
    //     }

    //     if (n % 2 != 0) {
    //         x *= myPow(x, abs(n) - 1);
    //     }
    //     else {
    //         x = myPow(x, abs(n) / 2);
    //         x *= x;
    //     }

    //     if (n < 0) {
    //         return 1 / x;
    //     }
    //     return x;
    // }
    double myPow(double x, int n) { // 2
        double result = 1;
        bool isNegativ = (n < 0);
        n = abs(n);
        while (n != 0) {
            if (n & 1) {
                result *= x;
            }
            n >>= 1;
            x *= x;
        }
        if (isNegativ) {
            return 1 / result;
        }
        return result;
    }
};

int main() {

    double x = 2;
    int n = -2;

    Solution s;

    cout << s.myPow(x, n);

    return 0;
}