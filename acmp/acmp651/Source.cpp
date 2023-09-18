#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
//#include <bits/stdc++.h>

int __gcd(int a, int b) {
	while (a != 0 && b != 0)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

int f(int s) {
	if (s == 1)
		return 0;
	int count = 1;

	for (int i = 2; i * i <= s;) {
		if (s % i == 0) {
			s /= i;
			++count;
		}
		else {
			++i;
		}
	}
	return count;
}

int main() {
	int a,b,c;
	scanf("%d %d", &a, &b);
	c = __gcd(a, b);
	printf("%d", f(a / c) + f(b / c));
}