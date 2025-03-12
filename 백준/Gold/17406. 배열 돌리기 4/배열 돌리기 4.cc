#include <bits/stdc++.h>
using namespace std;
int n, m,k;
int arr[51][51];
int temp[51][51];

void rotate(int r, int c, int s) {
	for (int layer = 1; layer <= s; layer++) {
		int x1 = r - layer, y1 = c - layer;
		int x2 = r + layer, y2 = c + layer;

		int prev = temp[x1][y1]; 
		
		for (int j = y1; j < y2; j++) swap(prev, temp[x1][j + 1]);
		
		for (int i = x1; i < x2; i++) swap(prev, temp[i + 1][y2]);
		
		for (int j = y2; j > y1; j--) swap(prev, temp[x2][j - 1]);
		
		for (int i = x2; i > x1; i--) swap(prev, temp[i - 1][y1]);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	vector<tuple<int, int, int>> op;
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		op.push_back({ a - 1,b - 1, c });
	}
	sort(op.begin(), op.end());
	int res = INT_MAX;
	do {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		for (auto a : op) {
			int r, c, s;
			tie(r, c, s) = a;
			// 배열 회전
			rotate(r,c,s);			
		}
		// 최솟값 구하고 갱신
		for (int i = 0; i < n; i++) {
			int tSum = 0;
			for (int j = 0; j < m; j++) {
				tSum += temp[i][j];
			}
			res = min(tSum, res);
		}
	} while (next_permutation(op.begin(), op.end()));
	cout << res;
}