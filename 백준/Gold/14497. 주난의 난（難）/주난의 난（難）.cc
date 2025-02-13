#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int x1, y_1, x2, y2;
char board[301][301];
bool vis[301][301];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {x,y}, 1 });
	vis[x][y] = true;
	int cnt = 0;
	while (board[x2 - 1][y2 - 1] != '0') {
		queue<pair<pair<int, int>, int>> new_q;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			cnt = cur.second;
			for (int i = 0; i < 4; i++) {
				int nx = cur.first.first + dx[i];
				int ny = cur.first.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (vis[nx][ny]) continue;
				vis[nx][ny] = true;
				if (board[nx][ny] != '0') {
					board[nx][ny] = '0';
					new_q.push({ {nx,ny}, cur.second + 1 });
				}
				else q.push({ {nx,ny} , cur.second });
			}
		}
		q = new_q;
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	
	cin >> x1 >> y_1 >> x2 >> y2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	cout << bfs(x1 - 1, y_1 - 1);
}