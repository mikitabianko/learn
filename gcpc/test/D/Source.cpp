#include <iostream>

using namespace std;

string f(string s, int a) {

    for (auto& el : s) {
        el = 'a' + ((el - 'a' + a) % 26);
    }

    return s;
}

int main() {

    string action; cin >> action;
    int n; cin >> n;

    int a = (action == "encrypt" ? 1 : 25);

    while (n--) {
        string str; cin >> str;
        cout << f(str, a) << "\n";
    }

    return 0;
}