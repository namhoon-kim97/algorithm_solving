#include <bits/stdc++.h>

using namespace std;

bool solution(string word) {
	stack<char> st;

	for (auto a : word) {
		if (!st.empty() && st.top() == a) {
			st.pop();
		}
		else {
			st.push(a);
		}
	}
	return st.empty();
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