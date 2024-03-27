import sys
from collections import *

input = sys.stdin.readline
n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]

q = deque()
q.append((0, 0))
vis = [False] * (k + 1)
while q:
    cur, cnt = q.popleft()
    if cur == k:
        print(cnt)
        break
    for i in coins:
        if cur + i <= k and not vis[cur + i]:
            q.append((cur + i, cnt + 1))
            vis[i + cur] = True
else:
    print(-1)
