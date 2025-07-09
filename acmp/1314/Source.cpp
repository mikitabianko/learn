#include <iostream>

using namespace std;

struct Box {
	int l, w, h;

	void rotate() {
		swap(l, w);
	}
};

bool isInsert(Box& a, Box& b, Box& c) {
	if (a.h < b.h || a.h < c.h) {
		return false;
	}
	if (a.w < b.w || a.w < c.w) {
		return false;
	}
	if (a.l < b.l || a.l < c.l) {
		return false;
	}

	if (a.l >= b.l + c.l) {
		return true;
	}
	if (a.w >= b.w + c.w) {
		return true;
	}
	if (a.h >= b.h + c.h) {
		return true;
	}

	return false;
}

bool check(Box& a, Box& b, Box& c) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (isInsert(c, a, b)) {
				return true;
			}
			a.rotate();
		}
		b.rotate();
	}
	return false;
}

int main() {
	Box a, b, c;

	cin >> a.l >> a.w >> a.h;
	cin >> b.l >> b.w >> b.h;
	cin >> c.l >> c.w >> c.h;

	cout << (check(a, b, c) ? "YES" : "NO");

	return 0;
}