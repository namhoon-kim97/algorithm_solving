import sys
from collections import *

input = sys.stdin.readline
dx = [1, 0, -1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]


m, n, h = map(int, input().split())  # 가로, 세로, 높이
box = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
dist = [[[0] * m for _ in range(n)] for _ in range(h)]
q = deque()
for k in range(h):
    for i in range(n):
        for j in range(m):
            if box[k][i][j] == 0:
                dist[k][i][j] = -1
            if box[k][i][j] == 1:
                q.append((k, i, j))  # z, x, y

while q:
    z, x, y = q.popleft()
    for i in range(6):
        nx = x + dx[i]
        ny = y + dy[i]
        nz = z + dz[i]
        if nx < 0 or ny < 0 or nz < 0 or nx >= n or ny >= m or nz >= h:
            continue
        if dist[nz][nx][ny] >= 0:  # 방문해서 갱신되었으면
            continue
        dist[nz][nx][ny] = dist[z][x][y] + 1
        q.append((nz, nx, ny))

ans = 0
for k in range(h):
    for i in range(n):
        for j in range(m):
            if dist[k][i][j] == -1:
                print(-1)
                exit()
            ans = max(ans, dist[k][i][j])
print(ans)
