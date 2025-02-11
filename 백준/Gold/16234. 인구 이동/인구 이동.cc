#include <bits/stdc++.h>
using namespace std;
int n, l,r, groupSum, groupCnt;
int board[51][51];
int vis[51][51];
bool vis2[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void solution(int x, int y, int* flag) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = 1;
	groupSum = board[x][y];
	groupCnt = 1;
	vector<pair<int, int>> group;
	group.push_back({ x,y });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (vis[nx][ny]) continue;
			if (abs(board[nx][ny] - board[cur.first][cur.second]) >= l && abs(board[nx][ny] - board[cur.first][cur.second]) <= r) {
				vis[nx][ny] = 1;
				groupCnt++;
				groupSum += board[nx][ny];
				group.push_back({ nx,ny });
				q.push({ nx,ny });
			}
		}
	}
	if (group.size() == 1) return ;
	for (auto a : group) {
		board[a.first][a.second] = groupSum / groupCnt;
		*flag = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0;
	while (1) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (vis[i][j] == 0) {
					solution(i, j, &flag);
				}
		}	
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + n, 0);
		}
		if (flag == 0) break;
		res++;
	}
	cout << res;
}