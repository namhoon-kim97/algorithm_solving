#include <bits/stdc++.h>

using namespace std;
int arr[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ b,a });
	}

	priority_queue <int, vector<int>, greater<int>> pq2;
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		pq2.push(cur.second);
		if (pq2.size() > cur.first) {
			pq2.pop();
		}
	}
	int res = 0;
	while (!pq2.empty()) {
		res += pq2.top();
		pq2.pop();
	}
	cout << res;
}