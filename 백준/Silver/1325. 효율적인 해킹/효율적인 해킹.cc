#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
bool vis[10001];
int n, m;

int bfs(int cur) {
	queue<int> q;
	q.push(cur);
	vis[cur] = true;
	int ret = 0;
	while (!q.empty()) {
		int nxt = q.front(); q.pop();
		for (auto a : adj[nxt]) {
			if (vis[a]) continue;
			vis[a] = true;
			q.push(a);
			ret++;
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	int maxNum = 0;
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		fill(vis, vis + n + 1, false);
		int ret = bfs(i);
		if (maxNum < ret) {
			maxNum = ret;
			res.clear();
			res.push_back(i);
		}
		else if (maxNum == ret) 
			res.push_back(i);
	}
	for (auto a : res)
		cout << a << ' ';
}