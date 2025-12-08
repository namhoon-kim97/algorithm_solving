#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];
int dp[1001][1001]; // dp[i][j] = (i,j)가 오른쪽 밑인 정사각형의 크기
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++) {
            board[i][j] = x[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = board[i][0];
    }

    for (int j = 0; j < m; j++) {
        dp[0][j] = board[0][j];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j] == 1) {
                dp[i][j] = min({ dp[i - 1][j - 1],dp[i][j - 1], dp[i - 1][j] }) + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans << '\n';
}