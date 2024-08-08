#include <bits/stdc++.h>

using namespace std;

char arr[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool vis[101][101];

int n, m;  // n: 세로, m: 가로

int bfs(int x, int y, char team) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    vis[x][y] = true;
    int count = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] || arr[nx][ny] != team) continue;

            vis[nx][ny] = true;
            q.push({ nx, ny });
            count++;
        }
    }

    return count * count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int wans = 0, bans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                if (arr[i][j] == 'W') {
                    wans += bfs(i, j, 'W');
                }
                else if (arr[i][j] == 'B') {
                    bans += bfs(i, j, 'B');
                }
            }
        }
    }

    cout << wans << ' ' << bans;
}