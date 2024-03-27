import sys
from collections import *


def is_all_melt():
    for i in range(n):
        for j in range(m):
            if board[i][j] != 0:
                return False
    return True


def is_separate():
    q = deque()
    vis = [[False] * m for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(m):
            if vis[i][j] or board[i][j] == 0:
                continue
            cnt += 1
            if cnt >= 2:
                return True
            q.append((i, j))
            vis[i][j] = True
            while q:
                x, y = q.popleft()
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if nx < 0 or ny < 0 or nx >= n or ny >= m:
                        continue
                    if vis[nx][ny] or board[nx][ny] == 0:
                        continue
                    vis[nx][ny] = True
                    q.append((nx, ny))
    return False


def melt():
    vis = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                vis[i][j] = True

    for i in range(n):
        for j in range(m):
            if board[i][j] != 0:
                for k in range(4):
                    nx = i + dx[k]
                    ny = j + dy[k]
                    if 0 <= nx < n and 0 <= ny < m and vis[nx][ny]:
                        board[i][j] -= 1
                    if board[i][j] < 0:
                        board[i][j] = 0


input = sys.stdin.readline
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

cnt = 0
while not is_separate():
    melt()
    cnt += 1
    if is_all_melt():
        print(0)
        exit()
print(cnt)
