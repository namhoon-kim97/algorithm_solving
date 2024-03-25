import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dfs(cur):
    for i in adj[cur]:
        if p[cur] == i:
            continue
        p[i] = cur
        dfs(i)


n = int(input())
adj = [[] for _ in range(n + 1)]
for i in range(n - 1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
p = [0] * (n + 1)
dfs(1)
print(*p[2:], sep="\n")
