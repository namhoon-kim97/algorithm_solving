#include <bits/stdc++.h>
using namespace std;
int n, l;
vector<vector<int>> board;
bool visRow[101][101]; // 가로 경사로 놓음 처리

bool isValid(vector<int>& path) {
	vector<bool> slope(n, false);  // 경사로 설치 여부 기록
	for (int i = 0; i < n - 1; i++) {
		int diff = path[i + 1] - path[i];
		if (diff == 0) continue;
		if (abs(diff) > 1) return false;
		
		if (diff == 1) {
			for (int j = 0; j < l; j++) {
				int idx = i - j;
				if (idx < 0 || path[idx] != path[i] || slope[idx]) return false;
				slope[idx] = true;
			}
		}
		else {
			for (int j = 1; j <= l; j++) {
				int idx = i + j;
				if (idx >= n || path[idx] != path[i + 1] || slope[idx]) return false;
				slope[idx] = true;
			}
		}

	}
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> l;
	board.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	

	// 행 확인
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (isValid(board[i])) cnt++;
	}

	// 열 확인
	vector<vector<int>> temp;
	temp.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	
			temp[j][n - 1 - i] = board[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (isValid(temp[i])) cnt++;
	}
	


	cout << cnt;

	
}