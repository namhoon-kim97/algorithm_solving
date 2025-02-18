#include <bits/stdc++.h>
using namespace std;

int n, res = INT_MAX;
int board[11][11];
bool vis[11][11];
bool vis2[11][11];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1};
vector<pair<int,int>> flowers;
void solution(int cnt) {
	if (cnt == 3) {
		// 꽃이 필 수 있는지
		// 꽃이 피면 얼마인지
		// res 갱신
		for (int i = 0; i < n; i++)
			fill(vis2[i], vis2[i] + n, false);
		int ret = 0;
		for (auto a : flowers) {
			vis2[a.first][a.second] = true;
			ret += board[a.first][a.second];
			for (int i = 0; i < 4; i++) {
				int nx = a.first + dx[i];
				int ny = a.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					return;
				if (vis2[nx][ny]) return;
				vis2[nx][ny] = true;
				ret += board[nx][ny];
			}
		}
		res = min(res, ret);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				vis[i][j] = true;
				flowers.push_back({ i,j });
				solution(cnt + 1);
				vis[i][j] = false;
				flowers.pop_back();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	solution(0);
	cout << res;
}