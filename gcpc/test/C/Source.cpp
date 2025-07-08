#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

double pi = 3.14159265358979323846;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    double a; cin >> a; 

    double b = (sqrt(a / pi) + 1) * 2.0;

    cout << fixed << setprecision(numeric_limits<long double>::digits10 + 1) << b * b;

    return 0;
}

// 1.273.239.687.465.095,9783727593