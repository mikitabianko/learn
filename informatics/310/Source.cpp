#include <iostream>

using namespace std;

int main() {
    int n; 
    cin >> n;

    int i = 2;
    
    while (i * i <= n) {
        if (n % i == 0) {
            cout << "composite";
            return 0;
        }
        ++i;
    }
    cout << "prime";

    return 0;
}