import sys
from collections import *

input = sys.stdin.readline

n = int(input())
m = int(input())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

vis = [False] * (n + 1)
deq = deque()
deq.append(1)
vis[1] = True
cnt = 0
while deq:
    cur = deq.popleft()
    for i in adj[cur]:
        if not vis[i]:
            deq.append(i)
            vis[i] = True
            cnt += 1

print(cnt)
