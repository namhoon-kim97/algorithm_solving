import sys
from collections import deque

input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def make_wall(cnt):
    if cnt == 3:
        vis = [[False] * (m + 1) for _ in range(n + 1)]
        temp = [[0] * (m + 1) for _ in range(n + 1)]
        q = deque()
        for i in range(n):
            for j in range(m):
                temp[i][j] = a[i][j]
                if a[i][j] == 2:
                    q.append((i, j))
        while q:
            x, y = q.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx < 0 or ny < 0 or nx >= n or ny >= m:
                    continue
                if vis[nx][ny] or temp[nx][ny] == 1 or temp[nx][ny] == 2:
                    continue
                temp[nx][ny] = 2
                vis[nx][ny] = True
                q.append((nx, ny))
        ans = 0
        for i in range(n):
            for j in range(m):
                if temp[i][j] == 0:
                    ans += 1
        global mx
        mx = max(mx, ans)
        return

    for i in range(n):
        for j in range(m):
            if a[i][j] == 0:
                a[i][j] = 1
                make_wall(cnt + 1)
                a[i][j] = 0


n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
mx = 0
make_wall(0)
print(mx)
