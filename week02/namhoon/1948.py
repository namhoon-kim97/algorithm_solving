import sys
from collections import *

input = sys.stdin.readline
n = int(input())
m = int(input())
indegree = [0] * (n + 1)
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, cost = map(int, input().split())
    indegree[b] += 1
    adj[a].append((b, cost))
st, en = map(int, input().split())
q = deque()
q.append(st)
dist = [0] * (n + 1)
path = [[] for _ in range(n + 1)]
while q:
    cur = q.popleft()
    for nxt, cost in adj[cur]:
        indegree[nxt] -= 1
        if dist[nxt] == dist[cur] + cost:
            path[nxt].append(cur)
        elif dist[nxt] < dist[cur] + cost:
            dist[nxt] = dist[cur] + cost
            path[nxt] = [cur]
        if indegree[nxt] == 0:
            q.append(nxt)

print(path)
print(dist[en])
ans = deque([en])
route = list()
while ans:
    now = ans.popleft()
    for x in path[now]:
        if (now, x) not in route:
            route.append((now, x))
            ans.append(x)
print(len(route))
