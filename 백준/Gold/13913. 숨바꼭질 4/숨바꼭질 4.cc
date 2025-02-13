#include <bits/stdc++.h>
using namespace std;
int dist[100001];
int res[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		
		vector<int> temp = { cur - 1, cur + 1, cur * 2 };
		for (auto nx : temp) {
			if (nx < 0 || nx > 100000) continue;
			if (dist[nx] == -1) {
				dist[nx] = dist[cur] + 1;
				
				res[nx] = cur;
				q.push(nx);
			}
		}
	}
	cout << dist[k] << '\n';
	int cur = k;
	vector<int> ans;
	while (cur != n) {
		ans.push_back(cur);
		cur = res[cur];
	}
	ans.push_back(n);
	reverse(ans.begin(), ans.end());
	for (auto a : ans)
		cout << a << ' ';
}	