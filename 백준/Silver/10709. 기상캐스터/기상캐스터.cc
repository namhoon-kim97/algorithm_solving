#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
bool vis[101][101];
int res[101][101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < h; i++) 
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'c') {
				q.push({ {i,j}, 0 });
				vis[i][j] = true;
			}
		}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			res[i][j] = -1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (arr[cur.first.first][cur.first.second] == 'c')
			res[cur.first.first][cur.first.second] = cur.second;
		int nx = cur.first.first;
		int ny = cur.first.second + 1;
		if (ny >= w || vis[nx][ny]) continue;
		arr[nx][ny] = 'c';
		q.push({ {nx,ny}, cur.second + 1 });
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << res[i][j] << ' ';
		cout << '\n';
	}
}