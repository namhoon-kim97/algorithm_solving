#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[300001];
int d[300001];
const int INF = 1e9 + 10;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v, e, k;
	cin >> v >> e >> k;
	fill(d, d + v + 1, INF);
	d[k] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push({ 0,k });
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
	}

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.first != d[cur.second]) continue;
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.first] <= d[cur.second] + nxt.second) continue;
			d[nxt.first] = nxt.second + d[cur.second];
			pq.push({ d[nxt.first], nxt.first});
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << '\n';
	}

	return 0;
}