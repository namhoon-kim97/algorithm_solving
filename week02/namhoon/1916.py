import sys
from heapq import *

input = sys.stdin.readline

n = int(input())
m = int(input())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, cost = map(int, input().split())
    adj[a].append((cost, b))

st, en = map(int, input().split())
d = [sys.maxsize] * (n + 1)
d[st] = 0
h = []
heappush(h, (0, st))
while h:
    cost, cur = heappop(h)
    if d[cur] != cost:
        continue
    for w, b in adj[cur]:
        if d[b] > w + cost:
            d[b] = w + cost
            heappush(h, (d[b], b))
print(d[en])
