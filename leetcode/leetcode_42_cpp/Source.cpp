#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
	stack<int> st;
	int ans = 0, temp = 0;

	for (auto& el : height) {
		if (st.empty())
			st.push(el);
		else 
			st.push(max(el, st.top()));
		ans += st.top() - el;
	}

	for (int i = height.size() - 1; i >= 0; --i) {
		temp = max(temp, height[i]);
		ans -= max(0, st.top() - temp);
		st.pop();
	}

	return ans;
}

int main() {
	vector<int> height = { 4,2,0,3,2,5 };
	cout << trap(height);
}