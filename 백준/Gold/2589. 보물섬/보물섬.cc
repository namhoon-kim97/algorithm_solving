#include <bits/stdc++.h>
using namespace std;
int n, m;
char board[51][51];
int vis[51][51];
vector<pair<int, int>> lands;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int solution(int x, int y) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			vis[i][j] = 0;

	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = 1;
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny] != 0 || board[nx][ny] == 'W') continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret = max(ret, *max_element(vis[i], vis[i] + m));
	return ret - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			board[i][j] = temp[j];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'L')
				res = max(res,solution(i, j));
		}
	}
	cout << res;
}