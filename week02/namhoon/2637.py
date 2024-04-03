import sys
from collections import *

input = sys.stdin.readline
n = int(input())  # 1~n-1까지 기본 or 중간부품 n은 완제품
m = int(input())
indegree = [0] * (n + 1)
basic_parts = set(range(1, n))
adj = [[] for _ in range(n + 1)]
parts_count = [[0] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    x, y, k = map(int, input().split())  # x를 만드는데 필요한 y가 k개 필요
    adj[y].append((x, k))
    indegree[x] += 1
    if x in basic_parts:
        basic_parts.remove(x)

q = deque()
for i in range(1, n + 1):
    if indegree[i] == 0:
        q.append(i)
        parts_count[i][i] = 1

while q:
    cur = q.popleft()
    for nxt, cost in adj[cur]:
        if nxt in basic_parts:
            parts_count[nxt][cur] += cost
        else:
            for i in range(1, n + 1):
                parts_count[nxt][i] += parts_count[cur][i] * cost
        indegree[nxt] -= 1
        if indegree[nxt] == 0:
            q.append(nxt)
print(parts_count)
for i in basic_parts:
    print(i, parts_count[n][i])
