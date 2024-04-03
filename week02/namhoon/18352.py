import sys
from collections import *

input = sys.stdin.readline
n, m, k, x = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)

dist = [-1] * (n + 1)
q = deque()
q.append(x)
dist[x] = 0
while q:
    cur = q.popleft()
    for i in adj[cur]:
        if dist[i] == -1:
            dist[i] = dist[cur] + 1
            q.append(i)
a = []
for i in range(1, len(dist)):
    if dist[i] == k:
        a.append(i)
if a:
    print(*a, sep="\n")
else:
    print(-1)
