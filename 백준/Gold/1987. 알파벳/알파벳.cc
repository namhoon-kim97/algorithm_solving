#include <bits/stdc++.h>

using namespace std;

char board[21][21];
bool vis[21][21];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int mxCnt = 0;
int r, c;
void dfs(int x, int y, int cnt, int num) {
	mxCnt = max(mxCnt, cnt);
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		int next = (1 << (int)(board[nx][ny] - 'A'));
		if ((num & next) == 0) 
			dfs(nx, ny, cnt + 1, num | next);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	bitset<26> alphabet;
	alphabet.set(board[0][0] - 'A');
	vis[0][0] = true;
	dfs(0, 0, 1, 1 << (int)(board[0][0] - 'A'));
	cout << mxCnt;
}