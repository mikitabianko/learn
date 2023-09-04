#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<string> parse(string& str) {
	vector<string> out;

	string temp = "";
	for (int i = 0; i < str.length(); ++i)
		if (str[i] == '/') {
			out.push_back(temp);
			temp = "";
		}
		else
			temp += str[i];
	out.push_back(temp);
	return out;
}

string simplifyPath(string path) {
	stack<string> st;
	for (auto& folder : parse(path))
		if (folder != "" && folder != "." && folder != "/")
			if (st.empty())
				st.push(folder);
			else if (folder == "..")
				st.pop();
			else
				st.push(folder);

	vector<string> temp;
	temp.reserve(st.size());

	while (!st.empty()) {
		temp.push_back(st.top());
		st.pop();
	}

	string ans = "";

	for (int i = temp.size() - 1; i >= 0; --i)
		if (temp[i] != "..")
			ans += "/" + temp[i];

	return ans == "" ? "/" : ans;
}

int main() {
	cout << simplifyPath("/a//b////c/d//././/..");
}