import sys, copy
from collections import *

input = sys.stdin.readline

m, n, h = map(int, input().split())  # 가로, 세로, 높이

box = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
dx = [1, 0, -1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]
q = deque()
dist = [[[0] * m for _ in range(n)] for _ in range(h)]
for j in range(m):
    for i in range(n):
        for k in range(h):
            if box[k][i][j] == 1:
                q.append((i, j, k, 0))
            if box[k][i][j] == 0:
                dist[k][i][j] = -1
while q:
    x, y, z, cnt = q.popleft()
    for i in range(6):
        nx = x + dx[i]
        ny = y + dy[i]
        nz = z + dz[i]
        if nx < 0 or ny < 0 or nz < 0 or nx >= n or ny >= m or nz >= h:
            continue
        if dist[nz][nx][ny] >= 0:
            continue
        dist[nz][nx][ny] = dist[z][x][y] + 1
        q.append((nx, ny, nz, cnt + 1))

ans = 0
for j in range(m):
    for i in range(n):
        for k in range(h):
            if dist[k][i][j] == -1:
                print(-1)
                exit()
            ans = max(ans, dist[k][i][j])
print(ans)
