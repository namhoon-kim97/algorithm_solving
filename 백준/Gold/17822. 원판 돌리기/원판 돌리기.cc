#include <bits/stdc++.h>

using namespace std;
int n, m, t;
vector<int> circles[51];
vector<int> temp[51];

void solution(int num, int dir, int cnt) { // dir 0 시계방향, 1 반시계방향
	cnt %= m;
	while (cnt--) {
		for (int i = 1; i <= n; i++) {
			if (i % num == 0) {  
				vector<int> temp = circles[i];
				if (dir == 0) {  // 시계 방향
					for (int j = 0; j < m; j++) {
						circles[i][j] = temp[(j + (m - 1)) % m];
					}
				}
				else {  // 반시계 방향
					for (int j = 0; j < m; j++) {
						circles[i][j] = temp[(j + 1) % m];
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		temp[i].clear();
		for (int j = 0; j < m; j++) {
			temp[i].push_back(circles[i][j]);
		}
	}
	
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) continue;
			if (temp[i][j] == temp[i][(j + (m - 1)) % m]) {
				circles[i][j] = 0;
				circles[i][(j + (m - 1)) % m] = 0;
				flag = true;
			}
			if (temp[i][j] == temp[i][(j + 1) % m]) {
				circles[i][j] = 0;
				circles[i][(j + 1) % m] = 0;
				flag = true;
			}

			int up = i - 1;
			int down = i + 1;
			if (up > 0 && temp[i][j] == temp[up][j]) {
				circles[i][j] = 0;
				circles[up][j] = 0;
				flag = true;
			}

			if (down <= n && temp[i][j] == temp[down][j] ) {
				circles[i][j] = 0;
				circles[down][j] = 0;
				flag = true;
			}
		}
	}
	
	if (!flag) {
		
		int sum = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (circles[i][j] != 0) {
					sum += circles[i][j];
					cnt++;
				}
			}
		}
		
		double average = (double)sum / cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (circles[i][j] == 0) continue;
				if ((double)circles[i][j] > average) circles[i][j]--;
				else if ((double)circles[i][j] < average) circles[i][j]++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			circles[i].push_back(a);
		}
	}

	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;

		solution(x, d, k);
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			res += circles[i][j];
		}
	}
	cout << res;
}