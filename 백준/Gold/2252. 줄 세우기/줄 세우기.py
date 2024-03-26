import sys
from collections import *

input = sys.stdin.readline

n, m = map(int, input().split())
indegree = [0] * (n + 1)
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    indegree[b] += 1
    adj[a].append(b)

q = deque()
for i in range(1, n + 1):
    if indegree[i] == 0:
        q.append(i)
ans = []
while q:
    cur = q.popleft()
    if indegree[cur] == 0:
        ans.append(cur)
    for i in adj[cur]:
        indegree[i] -= 1
        if indegree[i] == 0:
            q.append(i)
print(*ans)
