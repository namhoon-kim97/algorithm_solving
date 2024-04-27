import sys
from collections import deque

input = sys.stdin.readline
n = int(input())
indegree = [0] * (n + 1)
adj = [[] for _ in range(n + 1)]
times = [0]
for i in range(1, n + 1):
    temp = list(map(int, input().split()))
    times.append(temp[0])
    temp = temp[1:]
    for j in temp:
        if j == -1:
            break
        indegree[i] += 1
        adj[j].append(i)

q = deque()
for i in range(1, n + 1):
    if indegree[i] == 0:
        q.append(i)

result = [0] * (n + 1)
for i in range(1, n + 1):
    result[i] = times[i]
while q:
    cur = q.popleft()
    for i in adj[cur]:
        indegree[i] -= 1
        result[i] = max(result[i], result[cur] + times[i])
        if indegree[i] == 0:
            q.append(i)

result = result[1:]
print(*result, sep="\n")
