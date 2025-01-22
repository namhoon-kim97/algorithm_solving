#include <bits/stdc++.h>
using namespace std;
int m, n, k;
int arr[101][101];
int vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int st, int en, vector<int>& area) {
	queue<pair<int, int>> q;
	q.push({ st,en });
	int ret = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (vis[nx][ny] || arr[nx][ny] == 1) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
			ret++;
		}
	}
	area.push_back(ret);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for (int j = ly; j < ry; j++) {
			for (int k = lx; k < rx; k++) {
				arr[j][k] = 1;
			}
		}
	}
	
	int cnt = 0;
	vector<int> area;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (!vis[i][j] && arr[i][j] == 0) {
				vis[i][j] = 1;
				bfs(i, j, area);
				cnt++;
			}
		}
	cout << cnt << '\n';
	sort(area.begin(), area.end());
	for (auto a : area)
		cout << a << ' ';
}