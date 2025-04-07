#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int vis[1001][1001];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = {0,1,0,-1 };

bool bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.first == n - 1)
            return true;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] || arr[nx][ny] == 1) continue;
            vis[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
   
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j] - '0';
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (!vis[0][i] && arr[0][i] == 0) {
            vis[0][i] = true;
            if (bfs(0, i)) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}
