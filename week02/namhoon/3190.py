import sys
from collections import deque

input = sys.stdin.readline
deq = deque()

n = int(input())
board = [[0] * n for _ in range(n)]
vis = [[False] * n for _ in range(n)]
k = int(input())
for i in range(k):
    x, y = map(int, input().split())
    board[x - 1][y - 1] = 1

L = int(input())
snakes = deque()
for _ in range(L):
    x, c = input().split()
    snakes.append((x, c))
deq.append((0, 0))
vis[0][0] = True
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
dir_idx = 0
cnt = 0
while deq:

    if snakes and cnt == int(snakes[0][0]):
        _, c = snakes.popleft()
        if c == "D":
            dir_idx = (dir_idx + 1) % 4  # 오른쪽으로 회전
        else:
            dir_idx = (dir_idx - 1) % 4  # 왼쪽으로 회전

    cnt += 1
    cur = deq[-1]  # 뱀 머리 위치
    nx = cur[0] + directions[dir_idx][0]
    ny = cur[1] + directions[dir_idx][1]
    if nx < 0 or ny < 0 or nx >= n or ny >= n or vis[nx][ny]:
        print(cnt)
        break
    if board[nx][ny] == 1:
        board[nx][ny] = 0
    else:
        st_x, st_y = deq.popleft()
        vis[st_x][st_y] = False

    deq.append((nx, ny))
    vis[nx][ny] = True
