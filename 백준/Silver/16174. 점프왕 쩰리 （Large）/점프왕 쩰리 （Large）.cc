#include <bits/stdc++.h>

using namespace std;

int board[65][65];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[65][65];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<pair<int, int>,int>> q;
    q.push({ { 0,0 }, board[0][0] });
    vis[0][0] = true;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first.first + cur.second * dx[dir];
            int ny = cur.first.second + cur.second * dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny]) continue;
            if (board[nx][ny] == -1) {
                cout << "HaruHaru";
                return 0;
            }
            vis[nx][ny] = true;
            q.push({ {nx,ny}, board[nx][ny] });
        }
    }
    cout << "Hing";
}
