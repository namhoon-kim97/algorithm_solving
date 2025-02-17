#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> swan;
char board[1501][1501];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visWater[1501][1501];
bool visSwan[1501][1501];
queue<pair<int, int>> water, nextWater, swanQ, nextSwan;
pair<int, int> swan1, swan2;

bool swanMove() {
    while (!swanQ.empty()) {
        auto cur = swanQ.front(); swanQ.pop();
       
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visSwan[nx][ny]) continue;
            visSwan[nx][ny] = true;
            if (nx == swan2.first && ny == swan2.second) return true;
            if (board[nx][ny] == '.') {
                swanQ.push({ nx, ny });
            }
            else {
                nextSwan.push({ nx, ny });
            }
        }
    }
    return false;
}

void melt() {
    while (!water.empty()) {
        auto cur = water.front();
        int x = cur.first;
        int y = cur.second;
        water.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visWater[nx][ny]) continue;
            if (board[nx][ny] == 'X') {
                board[nx][ny] = '.';
                nextWater.push({ nx, ny }); // 다음 날 녹을 얼음 저장
            }
            visWater[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    bool foundSwan = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'L') {
                if (!foundSwan) {
                    swan1 = { i, j };
                    foundSwan = true;
                }
                else swan2 = { i, j };
                board[i][j] = '.';
            }
            if (board[i][j] == '.') {
                water.push({ i, j });
                visWater[i][j] = true;
            }
        }
    }

    swanQ.push(swan1);
    visSwan[swan1.first][swan1.second] = true;

    int days = 0;
    while (true) {
        if (swanMove()) break;
        melt();
        swap(swanQ, nextSwan);
        swap(water, nextWater);
        days++;
    }
    cout << days;
}