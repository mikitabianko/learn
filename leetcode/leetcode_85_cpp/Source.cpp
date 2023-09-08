#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& arr) {
	stack<int> st;
	int ans = 0, i = 0;

	while(!st.empty() || i < arr.size()) {
		if (st.empty() || (i < arr.size() && arr[i] >= arr[st.top()]))
			st.push(i++);
		else {
			int h = arr[st.top()];
			st.pop();
			ans = max(ans, h * (st.empty() ? i : i - st.top() - 1));
		}
	}
	return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	int ans = 0;
	vector<int> h(matrix[0].size(), 0);

	for (auto& row : matrix) {
		for (int i = 0; i < row.size(); ++i) {
			h[i] = row[i] == '0' ? 0 : h[i] + 1;
		}
		ans = max(ans, largestRectangleArea(h));
	}

	return ans;
}

int main() {
	vector<vector<char>> matrix = { {'1', '0', '1', '0', '0'},{'1', '0', '1', '1', '1'},{'1', '1', '1', '1', '1'},{'1', '0', '0', '1', '0'} };
	cout << maximalRectangle(matrix);
}