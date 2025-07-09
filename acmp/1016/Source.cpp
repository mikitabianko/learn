#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
	string num, name, surname, birth;
};

inline bool cmp(Student& a, Student& b) {
	if (a.num.length() < b.num.length()) return true;
	if (a.num.length() > b.num.length()) return false;
	if (a.num < b.num) return true;
	if (a.num > b.num) return false;
	return a.surname < b.surname;
}

int main() {
	int n;
	cin >> n;

	vector<Student> arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].surname >> arr[i].name >> arr[i].num >> arr[i].birth;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (auto& el : arr) {
		cout << el.num << ' ' << el.surname << ' ' << el.name << ' ' << el.birth << '\n';
	}
	return 0;
}