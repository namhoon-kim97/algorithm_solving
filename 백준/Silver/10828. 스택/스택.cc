#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	stack<int> st;
	while (n--) {
		string command;
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (command == "top") {
			if (st.empty()) cout << -1 << '\n';
			else cout << st.top() << '\n';

		}
		else if (command == "pop") {
			if (st.empty()) cout << -1 << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (command == "size") cout << st.size() << '\n';
		else if (command == "empty") {
			if (st.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}