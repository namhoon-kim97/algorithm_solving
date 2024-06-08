#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1};
int board[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			board[i][j] = temp[j] - '0';
		}
	}
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, -1)));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int broken = cur.second;
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first.first + dx[dir];
			int ny = cur.first.second + dy[dir];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (board[nx][ny] == 0 && dist[nx][ny][broken] == -1) {
				dist[nx][ny][broken] = dist[cur.first.first][cur.first.second][broken] + 1;
				q.push({ {nx,ny}, broken });
			}
			else if (board[nx][ny] == 1 && broken == 0 && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = dist[cur.first.first][cur.first.second][broken] + 1;
				q.push({ {nx,ny}, 1 });
			}
		}
	}
	int res = dist[n-1][m-1][0];
	if (res == -1 || (dist[n-1][m-1][1] != -1 && dist[n-1][m-1][1] < res)) {
		res = dist[n-1][m-1][1];
	}
	cout << res;
}