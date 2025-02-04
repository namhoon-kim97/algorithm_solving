import sys

input = sys.stdin.readline


def dfs(cur):
    ret = 0
    child = 0
    for i in adj[cur]:
        if i == m:
            continue
        ret += dfs(i)
        child += 1
    if child == 0:
        return 1
    return ret


n = int(input())
a = list(map(int, input().split()))
m = int(input())
adj = [[] for _ in range(n)]
root = 0
for i in range(n):
    if a[i] == -1:
        root = i
    else:
        adj[a[i]].append(i)
if root == m:
    print(0)
else:
    print(dfs(root))
