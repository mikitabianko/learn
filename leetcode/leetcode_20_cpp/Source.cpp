#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s) {
	map<char, char> d;
	d['('] = ')';
	d['['] = ']';
	d['{'] = '}';

	stack<char> st;
	for (auto& c : s)
		if (st.empty())
			st.push(c);
		else if (d[st.top()] == c)
			st.pop();
		else
			st.push(c);
	return st.empty();
}

int main() {
	cout << isValid("()") << '\n';
	cout << isValid("()[]{}") << '\n';
	cout << isValid("(]") << '\n';
}