#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}

	int res = 0;
	int curTime = 0;
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.first > curTime)
			curTime = cur.first;
		curTime += cur.second;
	}
	cout << curTime;

}