#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	stack<pair<int,int>> st;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		int cnt = 1;
		while (!st.empty() && st.top().first <= temp) {
			res += st.top().second;
			if (st.top().first == temp) {
				cnt = st.top().second + 1;
			}
			st.pop();
		}
		if (!st.empty()) res++;
		st.push({ temp, cnt });
	}
	cout << res;
}