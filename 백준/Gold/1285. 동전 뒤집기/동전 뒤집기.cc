#include <bits/stdc++.h>
using namespace std;
int n;
char board[21][21];
int backup[21];

void saveBoard(int N) {
	for (int i = 0; i < N; i++) {
		backup[i] = 0;
		for (int j = 0; j < N; j++)
			if (board[i][j] == 'T') backup[i] |= (1 << j);  // T면 1로 저장
	}
}

void restoreBoard(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			board[i][j] = (backup[i] & (1 << j)) ? 'T' : 'H';
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int res = INT_MAX;
	for (int i = 0; i < (1 << n); i++) {
		// 뒤집을 행을 결정
		saveBoard(n);
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < n; k++)
					board[j][k] == 'T' ? board[j][k] = 'H' : board[j][k] = 'T';
			}
		}
		// 뒤집을 열을 결정
		for (int j = 0; j < n; j++) {
			int hCnt = 0;
			int tCnt = 0;
			for (int k = 0; k < n; k++) {
				if (board[k][j] == 'T') tCnt++;
				else hCnt++;
			}
			if (tCnt > hCnt) {
				for (int k = 0; k < n; k++) {
					board[k][j] == 'T' ? board[k][j] = 'H' : board[k][j] = 'T';
				}
			}
		}
		int tCnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == 'T') tCnt++;
		res = min(res, tCnt);
		restoreBoard(n);
	}
	cout << res;
}