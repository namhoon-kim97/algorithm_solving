import sys
from collections import *

input = sys.stdin.readline
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
n = int(input())
board = [list(input().strip()) for _ in range(n)]
vis = [[False] * n for _ in range(n)]
q = deque()
q.append((0, 0, 0))  # x, y, 벽 제거 횟수
vis[0][0] = True

while q:
    curX, curY, cnt = q.popleft()
    if curX == n - 1 and curY == n - 1:
        print(cnt)
        break
    for i in range(4):
        nx = curX + dx[i]
        ny = curY + dy[i]

        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue
        if vis[nx][ny]:
            continue
        vis[nx][ny] = True
        if board[nx][ny] == "0":
            q.append((nx, ny, cnt + 1))
        else:
            q.appendleft((nx, ny, cnt))
