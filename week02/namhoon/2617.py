import sys
from collections import *

input = sys.stdin.readline


def dfs(a, cur):
    cnt = 0
    for i in a[cur]:
        if not vis[i]:
            vis[i] = True
            cnt += 1
            cnt += dfs(a, i)
    return cnt


n, m = map(int, input().split())
heavy = [[] for _ in range(n + 1)]
light = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    heavy[a].append(b)
    light[b].append(a)

mid = (n + 1) // 2
res = 0
for i in range(1, n + 1):
    vis = [False] * (n + 1)
    if dfs(heavy, i) >= mid:
        res += 1
    if dfs(light, i) >= mid:
        res += 1
print(res)
