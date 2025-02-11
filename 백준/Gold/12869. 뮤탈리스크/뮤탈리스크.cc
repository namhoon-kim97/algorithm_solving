#include <bits/stdc++.h>
using namespace std;
int arr[4];
int res;
bool vis[61][61][61];
int dir[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,3,9},
	{1,9,3}
};
struct State {
	int a, b, c, cnt;
};

int bfs() {
	queue<State> q;
	q.push({ arr[0], arr[1], arr[2], 0 });
	vis[arr[0]][arr[1]][arr[2]] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.a == 0 && cur.b == 0 && cur.c == 0)
			return cur.cnt;
		for (int i = 0; i < 6; i++) {
			int nx = max(0,cur.a - dir[i][0]);
			int ny = max(0,cur.b - dir[i][1]);
			int nz = max(0,cur.c - dir[i][2]);
			if (vis[nx][ny][nz]) continue;
			vis[nx][ny][nz] = 1;
			q.push({ nx,ny,nz,cur.cnt + 1 });
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << bfs();
}