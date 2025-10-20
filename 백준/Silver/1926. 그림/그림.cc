#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
bool vis[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = {0,1,0,-1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    int cnt = 0;
    int area = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && !vis[i][j]) {
                vis[i][j] = true;
                q.push({ i,j });
                cnt++;
                int curCnt = 0;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    curCnt++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (arr[nx][ny] == 0 || vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        q.push({ nx,ny });
                    }
                }
                area = max(area, curCnt);
            }
        }
    }
    cout << cnt << '\n' << area;
}