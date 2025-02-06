#include <bits/stdc++.h>
using namespace std;
int res[1000001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> arr;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	fill(res, res + n + 1, -1);
	for (int i = 0; i < n; i++) {
		while (!st.empty() && arr[st.top()] < arr[i]) {
			res[st.top()] = arr[i]; st.pop();
		}
		st.push(i);
	}

	
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	
	
}