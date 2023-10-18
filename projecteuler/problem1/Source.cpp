//projecteuler.net/problem=1
#include <iostream>

using namespace std;

int main() {

	int ans = 0, n = 1000;

	for (int i = 0; i < n; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			ans += i;
		}
	}

	cout << ans; // 233168

	return 0;
}