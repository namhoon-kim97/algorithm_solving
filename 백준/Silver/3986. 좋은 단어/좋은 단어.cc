#include <bits/stdc++.h>

using namespace std;

bool solution(string word) {
	stack<char> st;

	for (auto a : word) {
		st.push(a);
	}

	stack<char> st2;
	while(!st.empty()) {
		char temp = st.top(); st.pop();
		if (!st.empty() && temp == st.top()) {
			st.pop();
			continue;
		}
		if (!st2.empty() && st2.top() == temp) {
			st2.pop();
			continue;
		}
		st2.push(temp);
	}
	if (!st.empty() || !st2.empty())
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> arr;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (solution(arr[i]))
			ans++;
	}
	cout << ans;
}