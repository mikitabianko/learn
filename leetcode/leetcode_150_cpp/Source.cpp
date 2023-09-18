#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

pair<int, int> getTwoLast(stack<int>& st) {
	auto p = make_pair(0, st.top());
	st.pop();
	p.first = st.top();
	st.pop();
	return p;
}

int evalRPN(vector<string>& tokens) {
	stack<int> st;
	pair<int, int> tmp;

	for (auto& token : tokens) {
		if (token == "+") {
			tmp = getTwoLast(st);
			st.push(tmp.first + tmp.second);
		}
		else if (token == "-") {
			tmp = getTwoLast(st);
			st.push(tmp.first - tmp.second);
		}
		else if (token == "*") {
			tmp = getTwoLast(st);
			st.push(tmp.first * tmp.second);
		}
		else if (token == "/") {
			tmp = getTwoLast(st);
			st.push(tmp.first / tmp.second);
		}
		else {
			st.push(stoi(token));
		}
	}
	return st.top();
}

int main() {
	vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	cout << evalRPN(tokens);
}