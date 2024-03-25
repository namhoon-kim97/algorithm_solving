import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dfs(cur):
    vis[cur] = True
    ret = 0
    for i in adj[cur]:
        if a[i - 1] == "1":
            ret += 1
        elif not vis[i] and a[i - 1] == "0":
            ret += dfs(i)
    return ret


n = int(input())
a = input().strip()
adj = [[] for _ in range(n + 1)]
cnt = 0
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

    if a[u - 1] == "1" and a[v - 1] == "1":
        cnt += 2
vis = [False] * (n + 1)
for i in range(1, n + 1):
    if a[i - 1] == "0" and not vis[i]:
        res = dfs(i)  # -> 여기서 i번에서 출발한 경우의 수를 구해야함.
        cnt += res * (res - 1)
print(cnt)
