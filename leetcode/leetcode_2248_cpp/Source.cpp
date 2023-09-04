#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> intersection(vector<vector<int>>& nums) {
	map<int, int> mp;

	for (auto& row : nums)
		for (auto& el : row)
			++mp[el];

	vector<int> ans;

	for (auto& el : mp)
		if (el.second == nums.size())
			ans.push_back(el.first);

	return ans;
}

int main() {
	vector<vector<int>> nums = { {3,1,2,4,5}, {1,2,3,4}, {3,4,5,6} };

	for (auto& el : intersection(nums))
		cout << el << ' ';
}