#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[5][5];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.length(); j++) {
            board[i][j] = temp[j] - '0';
        }
    }

    int res = 0;
	for (int bitmask = 0; bitmask < (1 << (n * m)); bitmask++) {
		int totalSum = 0;
        // 가로
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < m; j++) {
                int idx = i * m + j;
                if ((bitmask & (1 << idx)) == 0) {
                    num = num * 10 + board[i][j];
                }
                else {
                    totalSum += num;
                    num = 0;
                }
            }
            totalSum += num;
        }

        // 세로
        for (int i = 0; i < m; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                int idx = j * m + i;
                if ((bitmask & (1 << idx)) != 0) {
                    num = num * 10 + board[j][i];
                }
                else {
                    totalSum += num;
                    num = 0;
                }
            }
            totalSum += num;
        }

        res = max(res, totalSum);
	}
    cout << res;
}