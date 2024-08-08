#include <bits/stdc++.h>

using namespace std;

char arr[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    for (int i = 0 ; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }

    int wans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && arr[i][j] == 'W') {
                queue<pair<int, int>> q;
                q.push({ i,j });
                vis[i][j] = true;
                int wcnt = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (vis[nx][ny] || arr[nx][ny] != 'W') continue;
                        vis[nx][ny] = true;
                        q.push({ nx,ny });
                        wcnt++;
                    }
                }
                wans += (wcnt * wcnt);
            }

        }
    }

    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + m, false);

    int bans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && arr[i][j] == 'B') {
                queue<pair<int, int>> q;
                q.push({ i,j });
                vis[i][j] = true;
                int bcnt = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (vis[nx][ny] || arr[nx][ny] != 'B') continue;
                        bcnt++;
                        vis[nx][ny] = true;
                        q.push({ nx,ny });
                    }
                }
                bans += (bcnt * bcnt);
            }
        }
    }
    
    cout << wans << ' ' << bans;
   
}