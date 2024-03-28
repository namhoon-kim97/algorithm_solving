import sys
from heapq import *
from collections import *

input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    indegree[b] += 1

ans = []
h = []

for i in range(1, n + 1):
    if indegree[i] == 0:
        heappush(h, i)

while h:
    cur = heappop(h)
    ans.append(cur)
    for i in adj[cur]:
        indegree[i] -= 1
        if indegree[i] == 0:
            heappush(h, i)
print(*ans)
