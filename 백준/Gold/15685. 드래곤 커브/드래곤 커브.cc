#include <bits/stdc++.h>
using namespace std;
int n,x,y,d,g;
vector<int> dragon[4][11];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int vis[101][101];

void solution(int x, int y, int d, int g) {
	vis[x][y] = 1;
	for (int i = 0; i <= g; i++) {
		for (int dir : dragon[d][i]) {
			x += dx[dir];
			y += dy[dir];
			vis[x][y] = 1;
		}
	}
}

void make() {
	for (int i = 0; i < 4; i++) {
		dragon[i][0].push_back(i);
		dragon[i][1].push_back((i + 1) % 4);
		for (int j = 2; j <= 10; j++) {
			int n = dragon[i][j - 1].size();
			for (int k = n - 1; k >= 0; k--) {
				dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
			}
			for (int k = 0; k < n; k++) {
				dragon[i][j].push_back(dragon[i][j - 1][k]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	make();
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		solution(x, y, d, g);
	}
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (vis[i][j] && vis[i + 1][j] && vis[i + 1][j + 1] && vis[i][j + 1]) cnt++;
		}
	}
	cout << cnt;
}