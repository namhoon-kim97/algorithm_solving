#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	string temp;
	cin >> temp;

	stack<int> st;
	int lastInvalid = -1;
	int res = 0;
	
	for (int i = 0; i < n; i++) {
		if (temp[i] == '(') {
			st.push(i);
		}
		else {
			if (st.empty()) {
				lastInvalid = i;
			}
			else {
				st.pop();
				if (st.empty()) {
					res = max(res, i - lastInvalid);
				}
				else {
					res = max(res, i - st.top());
				}
			}
		}
	}
	cout << res;
}

// 12
// (()(()()(()(