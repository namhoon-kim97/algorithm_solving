#include <bits/stdc++.h>

using namespace std;
int m, n;
int board[51][51];
bool vis[51][51];
int roomMap[51][51];
int dx[4] = { 1,0,-1,0 }; // 남, 동, 북, 서
int dy[4] = { 0,1,0,-1 };
int dir[4] = { 8,4,2,1}; // 남, 동, 북, 서

int solution(int x, int y, int roomId) {
	queue<pair<int, int>> q;
	q.push({  x,y });
	int ret = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		ret++;
		for (int i = 0; i < 4; i++) {
			if ((board[cur.first][cur.second] & dir[i]) != 0) continue;
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (vis[nx][ny]) continue;
			vis[nx][ny] = true;
			roomMap[nx][ny] = roomId;
			q.push( {nx,ny});
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	int cnt = 0;
	int maxArea = 0;
	vector<int> roomSize; // 각 방의 크기 저장
	int roomId = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				vis[i][j] = true;
				roomMap[i][j] = roomId;
				int area = solution(i, j, roomId);
				maxArea = max(maxArea, area);
				cnt++;
				roomSize.push_back(area);
				roomId++;
			}
		}
	}
	int maxNewArea = maxArea;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if ((board[i][j] & dir[k]) == 0) continue;
				if (roomMap[i][j] == roomMap[nx][ny]) continue;
				int newSize = roomSize[roomMap[i][j]] + roomSize[roomMap[nx][ny]];
				maxNewArea = max(newSize, maxNewArea);
			}
		}
	}


	cout << cnt << '\n' << maxArea << '\n' << maxNewArea;
}