import sys
from collections import *

input = sys.stdin.readline
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())
q = deque()

a = [input().strip() for _ in range(n)]
vis = [[False] * m for _ in range(n)]
q.append((0, 0, 1))  # x,y,cnt

while q:
    curX, curY, cnt = q.popleft()
    if curX == n - 1 and curY == m - 1:
        print(cnt)
        break
    for i in range(4):
        nx = curX + dx[i]
        ny = curY + dy[i]
        if nx < 0 or ny < 0 or nx >= n or ny >= m:
            continue
        if vis[nx][ny] or a[nx][ny] == "0":
            continue
        vis[nx][ny] = True
        q.append((nx, ny, cnt + 1))
