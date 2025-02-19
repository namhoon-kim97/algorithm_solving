#include <bits/stdc++.h>
using namespace std;
int n, m, h;
int res = INT_MAX;
bool vis[31][11];

bool check() {
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 1; j <= h; j++) {
			if (vis[j][pos]) pos++;
			else if (pos > 1 && vis[j][pos - 1]) pos--;
		}
		if (pos != i) return false;
	}
	return true;
}

void solution(int cnt, int limit) {
	if (cnt == limit) {
		// 사다리 판독
		if (check())
			res = min(res, cnt);
		return;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (!vis[i][j] && !vis[i][j - 1] && !vis[i][j + 1]) {
				vis[i][j] = true;
				solution(cnt + 1, limit);
				vis[i][j] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vis[a][b] = true;
	}
	
	for (int i = 0; i <= 3; i++) {
		solution(0, i);
		if (res != INT_MAX) {
			cout << res;
			return 0;
		}
	}
	cout << -1;
}