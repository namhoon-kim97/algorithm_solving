import sys
from collections import deque

input = sys.stdin.readline
n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
vis = [[False] * n for _ in range(n)]
q = deque()
q.append((0, 0))
while q:
    x, y = q.popleft()
    if a[x][y] == -1:
        print("HaruHaru")
        exit()

    nx = x + a[x][y]
    if 0 <= nx < n and (vis[nx][y] or a[nx][y] != 0):
        vis[nx][y] = True
        q.append((nx, y))

    ny = y + a[x][y]
    if 0 <= ny < n and (vis[x][ny] or a[x][ny] != 0):
        vis[x][ny] = True
        q.append((x, ny))
print("Hing")
