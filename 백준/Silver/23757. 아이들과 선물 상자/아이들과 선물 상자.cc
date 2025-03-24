#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int arr2[100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	priority_queue<int, vector<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	for (int i = 0; i < m; i++) {
		if (pq.empty()) {
			cout << 0;
			return 0;
		}

		int cur = pq.top(); pq.pop();
		if (cur >= arr2[i]) {
			pq.push(cur - arr2[i]);
		}
		else {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}
