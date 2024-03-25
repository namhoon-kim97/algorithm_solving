import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dfs(cur):
    global cnt
    if a[cur - 1] == "1" and vis[cur] != 1:
        cnt += 1
        return
    vis[cur] = 0
    for i in adj[cur]:
        if vis[i] == -1:
            dfs(i)


n = int(input())
a = input().strip()
adj = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

cnt = 0
for i in range(1, n + 1):
    if a[i - 1] == "1":
        vis = [-1] * (n + 1)
        vis[i] = 1
        dfs(i)  # -> 여기서 i번에서 출발한 경우의 수를 구해야함.
print(cnt)
