import sys
from collections import deque
from itertools import combinations
import copy

input = sys.stdin.readline
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def spread(temp_a):
    global res
    q = deque()
    for i in range(n):
        for j in range(m):
            if temp_a[i][j] == 2:
                q.append([i, j])

    while len(q) != 0:
        cur = q.popleft()
        for i in range(4):
            nx = cur[0] + dx[i]
            ny = cur[1] + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if temp_a[nx][ny] != 0:
                continue
            temp_a[nx][ny] = 2
            q.append([nx, ny])

    cnt = 0
    for i in range(n):
        for j in range(m):
            if temp_a[i][j] == 0:
                cnt += 1
    res = max(res, cnt)


n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
empty_spaces = [(i, j) for i in range(n) for j in range(m) if a[i][j] == 0]
res = 0

for wall in combinations(empty_spaces, 3):
    temp_a = copy.deepcopy(a)
    for i, j in wall:
        temp_a[i][j] = 1
    spread(temp_a)

print(res)
