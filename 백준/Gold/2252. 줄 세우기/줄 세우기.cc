#include <bits/stdc++.h>
using namespace std;

int indegree[32001];
vector<int> adj[32001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		for (auto nxt : adj[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0)
				q.push(nxt);
		}
	}
}