import sys
from collections import *

input = sys.stdin.readline
q = deque()
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
r, c = map(int, input().split())
board = [list(input().strip()) for _ in range(r)]
water_dist = [[0] * c for _ in range(r)]
beaver_dist = [[0] * c for _ in range(r)]
water = deque()
beaver = deque()
for i in range(r):
    for j in range(c):
        if board[i][j] == ".":
            water_dist[i][j] = -1
            beaver_dist[i][j] = -1
        if board[i][j] == "*":
            water.append((i, j))
        if board[i][j] == "S":
            water_dist[i][j] = -1
            beaver.append((i, j))
        if board[i][j] == "D":
            beaver_dist[i][j] = -1
            water_dist[i][j] = sys.maxsize
            en_x = i
            en_y = j
while water:
    wx, wy = water.popleft()
    for i in range(4):
        nx = wx + dx[i]
        ny = wy + dy[i]
        if nx < 0 or ny < 0 or nx >= r or ny >= c:
            continue
        if water_dist[nx][ny] >= 0 or board[nx][ny] == "X" or board[nx][ny] == "D":
            continue
        water_dist[nx][ny] = water_dist[wx][wy] + 1
        water.append((nx, ny))

while beaver:
    bx, by = beaver.popleft()
    for i in range(4):
        nx = bx + dx[i]
        ny = by + dy[i]
        if nx < 0 or ny < 0 or nx >= r or ny >= c:
            continue
        if (
            beaver_dist[nx][ny] >= 0
            or (
                beaver_dist[bx][by] + 1 >= water_dist[nx][ny]
                and water_dist[nx][ny] != -1
            )
            or board[nx][ny] == "X"
        ):
            continue
        beaver_dist[nx][ny] = beaver_dist[bx][by] + 1
        beaver.append((nx, ny))

if beaver_dist[en_x][en_y] != -1:
    print(beaver_dist[en_x][en_y])
else:
    print("KAKTUS")
