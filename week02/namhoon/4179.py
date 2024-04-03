import sys
from collections import *

input = sys.stdin.readline
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
r, c = map(int, (input().split()))
board = [input().strip() for _ in range(r)]
person = deque()
fire = deque()
fire_cnt = [[-1] * c for _ in range(r)]
person_cnt = [[-1] * c for _ in range(r)]
for i in range(r):
    for j in range(c):
        if board[i][j] == "J":
            person.append((i, j))
            person_cnt[i][j] = 0
        if board[i][j] == "F":
            fire.append((i, j))
            fire_cnt[i][j] = 0
while fire:
    x, y = fire.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= r or ny >= c:
            continue
        if board[nx][ny] == "#" or fire_cnt[nx][ny] >= 0:
            continue
        fire_cnt[nx][ny] = fire_cnt[x][y] + 1
        fire.append((nx, ny))

while person:
    x, y = person.popleft()
    if x == r - 1 or y == c - 1 or x == 0 or y == 0:
        print(person_cnt[x][y] + 1)
        exit()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= r or ny >= c:
            continue
        if board[nx][ny] == "#" or person_cnt[nx][ny] >= 0:
            continue
        if (person_cnt[x][y] + 1 >= fire_cnt[nx][ny]) and fire_cnt[nx][ny] != -1:
            continue
        person_cnt[nx][ny] = person_cnt[x][y] + 1
        person.append((nx, ny))

print("IMPOSSIBLE")
