import sys
from collections import *

input = sys.stdin.readline


def iterdfs():
    stack = []
    stack.append(st)
    while stack:
        cur = stack.pop()
        if vis[cur]:
            continue
        vis[cur] = True
        print(cur, end=" ")
        for i in range(len(adj[cur])):
            nxt = adj[cur][len(adj[cur]) - 1 - i]
            if not vis[nxt]:
                stack.append(nxt)


def dfs(cur):
    vis[cur] = True
    print(cur, end=" ")
    for i in adj[cur]:
        if vis[i]:
            continue
        dfs(i)


def bfs():
    deq = deque()
    deq.append(st)
    vis[st] = True
    while deq:
        cur = deq.popleft()
        print(cur, end=" ")
        for i in adj[cur]:
            if vis[i]:
                continue
            deq.append(i)
            vis[i] = True


n, m, st = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

for i in adj:
    i.sort()

vis = [False] * (n + 1)
dfs(st)
vis = [False] * (n + 1)
print()
bfs()
