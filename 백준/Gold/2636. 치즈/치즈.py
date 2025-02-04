import sys
from collections import deque

input = sys.stdin.readline
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def check():
    for i in range(n):
        for j in range(m):
            if a[i][j] == 1:
                return True
    return False


def check_edge(x, y, vis):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= n or ny >= m:
            continue
        if vis[nx][ny]:
            return True
    return False


def melt(vis):
    q = deque()
    q.append((0, 0))
    vis[0][0] = True
    while len(q) != 0:
        cur = q.popleft()
        for i in range(4):
            nx = cur[0] + dx[i]
            ny = cur[1] + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if vis[nx][ny] or a[nx][ny] != 0:
                continue
            vis[nx][ny] = True
            q.append((nx, ny))

    for i in range(n):
        for j in range(m):
            if a[i][j] == 1:
                if check_edge(i, j, vis):
                    a[i][j] = 0


def bfs():
    global last_cheese
    cnt = 0
    while check():  # 치즈가 있는지
        # 녹임
        last_cheese = sum(row.count(1) for row in a)
        vis = [[False] * m for _ in range(n)]
        melt(vis)
        cnt += 1
    return cnt


n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

last_cheese = 0
print(bfs())
print(last_cheese)
