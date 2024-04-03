import sys
from heapq import *

input = sys.stdin.readline

v, m = map(int, input().split())
adj = [[] for _ in range(v + 1)]
vis = [False] * (v + 1)
for _ in range(m):
    a, b, cost = map(int, input().split())
    adj[b].append((cost, a))
    adj[a].append((cost, b))

vis[1] = True
h = []
cnt = 0
ans = 0
for cost, dest in adj[1]:
    heappush(h, (cost, 1, dest))
while cnt < v - 1:
    cost, cur, dest = heappop(h)
    if vis[dest]:
        continue
    vis[dest] = True
    cnt += 1
    ans += cost
    for cost, dest2 in adj[dest]:
        if not vis[dest2]:
            heappush(h, (cost, dest, dest2))
print(ans)
