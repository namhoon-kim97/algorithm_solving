import sys
from heapq import *

input = sys.stdin.readline

V, E = map(int, input().split())
st = int(input())
adj = [[] for _ in range(V + 1)]
d = [sys.maxsize] * (V + 1)
for _ in range(E):
    u, v, w = map(int, input().split())
    adj[u].append((w, v))

d[st] = 0
h = []
heappush(h, (d[st], st))
while h:
    cost, cur = heappop(h)
    if d[cur] != cost:
        continue
    for w, dest in adj[cur]:
        if d[dest] <= d[cur] + w:
            continue
        d[dest] = d[cur] + w  # 거쳐가는 비용이 더 낮으면 업데이트
        heappush(h, (d[dest], dest))

for i in range(1, V + 1):
    if d[i] == sys.maxsize:
        print("INF")
    else:
        print(d[i])
