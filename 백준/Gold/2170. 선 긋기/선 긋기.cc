#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}

	int st = pq.top().first;
	int en = pq.top().second;
	pq.pop();
	int res = 0;
	while (!pq.empty()) {
		if (en > pq.top().first) {
			en = max(en,pq.top().second);
		}
		else {
			res += abs(en - st);
			st = pq.top().first;
			en = pq.top().second;
		}

		pq.pop();
	}
	res += abs(en - st);
	cout << res;
}