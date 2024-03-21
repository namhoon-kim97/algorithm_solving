#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> st;
	while (n--) {
		int temp;
		cin >> temp;
		if (temp != 0) st.push(temp);
		else st.pop();
	}

	int ans = 0;
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans;
}