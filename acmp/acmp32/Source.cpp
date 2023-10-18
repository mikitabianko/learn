#include <iostream>
#include <algorithm>
#include <string>

bool decrease(const char& a, const char& b) {
	return b != '-' && (a == '-' || a > b);
}

bool increase(const char& a, const char& b) {
	return b != '-' && (a == '-' || a < b);
}

void moveZeros(std::string& str) {
	int it = 0, s = (str[0] == '-' ? 1 : 0);
	while (it < str.size() && str[it + s] == '0') {
		++it;
	}
	str.erase(s, it);
	str.insert(s + 1, it, '0');
}

int main() {
	std::string n1, n2;

	std::cin >> n1 >> n2;

	sort(n1.begin(), n1.end(), n1[0] != '-' ? decrease : increase);
	sort(n2.begin(), n2.end(), n2[0] != '-' ? increase : decrease);

	if (n1[0] == '-' && n1.size() > 1) moveZeros(n1);
	if (n2[0] != '-' && n2.size() > 1) moveZeros(n2);

	std::cout << stoi(n1) - stoi(n2);

	return 0;
}