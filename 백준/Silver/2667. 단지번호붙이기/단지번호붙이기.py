import sys
from collections import *

input = sys.stdin.readline
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
n = int(input())
board = [list(map(int, input().strip())) for _ in range(n)]
q = deque()
vis = [[False] * n for _ in range(n)]
ans = []
dcnt = 0
for i in range(n):
    for j in range(n):
        if vis[i][j] or board[i][j] == 0:
            continue
        hcnt = 1
        dcnt += 1
        vis[i][j] = True
        q.append((i, j))  # x,y
        while q:
            x, y = q.popleft()
            for dir in range(4):
                nx = x + dx[dir]
                ny = y + dy[dir]
                if nx < 0 or ny < 0 or nx >= n or ny >= n:
                    continue
                if vis[nx][ny] or board[nx][ny] == 0:
                    continue
                vis[nx][ny] = True
                hcnt += 1
                q.append((nx, ny))
        ans.append(hcnt)

ans.sort()
print(dcnt)
print(*ans, sep="\n")
