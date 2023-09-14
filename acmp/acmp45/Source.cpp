#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << 10;
		return 0;
	}

	if (n == 1) {
		cout << 1;
		return 0;
	}

	int nums[10];
	for (int i = 0; i < 10; ++i)
		nums[i] = 0;

	for (int i = 9; n && i >= 2;) {
		if (!(n % i)) {
			n /= i;
			++nums[i];
		}
		else {
			--i;
		}
	}

	if (n > 1) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < nums[i]; ++j) 
			cout << i;
	}
}