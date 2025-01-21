#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0,0 }, 1 });
	vis[0][0] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.first.first == n - 1 && cur.first.second == m - 1) {
			cout << cur.second;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.first.first + dx[i];
			int ny = cur.first.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny] || arr[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			q.push({ {nx,ny}, cur.second + 1 });
		}
	}
}
