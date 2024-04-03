import sys
from heapq import *

input = sys.stdin.readline
n = int(input())
adj = [[] for _ in range(n + 1)]
outdegree = [0] * (n + 1)
res = [0] * (n + 1)

for i in range(1, n + 1):
    conn = list(map(int, input().strip()))
    for idx, val in enumerate(conn):
        if val == 1:
            adj[idx + 1].append(i)
            outdegree[i] += 1

h = []
for i in range(1, n + 1):
    if outdegree[i] == 0:
        heappush(h, -i)

while h:
    cur = -heappop(h)
    res[cur] = n
    for i in adj[cur]:
        outdegree[i] -= 1
        if outdegree[i] == 0:
            heappush(h, -i)
    n -= 1

if res.count(0) > 2:
    print(-1)
else:
    print(" ".join(map(str, res[1:])))
