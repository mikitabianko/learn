#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

//CNT Name Surname N1 N2 N3 N4 N5 N6
struct Result {
	string cnt, name, surname;
	vector<int> n;
};

int main() {
	int n;
	cin >> n;

	vector<Result> arr;

	while (n--) {
		Result el;
		cin >> el.cnt >> el.name >> el.surname;
		string temp;
		for (int i = 0; i < 6; ++i) {
			cin >> temp;
			if (temp != "x") {
				el.n.push_back(100 * (temp[0] - '0') + 10 * (temp[2] - '0') + temp[3] - '0');
			}
		}
		if (!el.n.empty()) {
			sort(el.n.rbegin(), el.n.rend());
			arr.push_back(el);
		}
	}

	sort(arr.begin(), arr.end(), [](Result& a, Result& b) {
		return a.n > b.n;
	});

	if (arr.size() > 3) {
		arr.resize(3);
	}

	for (int i = 0; i < (int)arr.size(); ++i) {
		printf("%d) %s %s %s %.2f\n", i + 1, arr[i].cnt.c_str(), arr[i].name.c_str(), arr[i].surname.c_str(), arr[i].n[0] / 100.0);
	}

	if (arr.empty()) {
		cout << "No results.";
	}
}