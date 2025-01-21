#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;

int bfs(int limit) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		fill(vis[i], vis[i] + n, 0);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j] && arr[i][j] > limit) {
				vis[i][j] = 1;
				q.push({ i,j });
				cnt++;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (vis[nx][ny] || arr[nx][ny] <= limit) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> arr[i][j];

	int res = 0;
	for (int i = 0; i <= 100; i++) {
		res = max(res, bfs(i));
	}
	cout << res;
}
