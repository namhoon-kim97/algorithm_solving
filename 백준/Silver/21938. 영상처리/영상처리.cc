#include <bits/stdc++.h>
using namespace std;

int arr[1001][3003];
int newArr[1001][1001];
bool vis[1001][1001];
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1};
int n, m;

void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny] || newArr[nx][ny] != 255) continue;
			vis[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m * 3; j++) {
			cin >> arr[i][j];
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m * 3; j += 3) {
			int temp = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2]) / 3;
			temp >= t ? newArr[i][j / 3] = 255 : newArr[i][j / 3] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && newArr[i][j] == 255) {
				vis[i][j] = true;
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}