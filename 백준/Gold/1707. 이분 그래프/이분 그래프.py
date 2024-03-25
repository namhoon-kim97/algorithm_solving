import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**5)


def dfs(cur, color):
    global check
    colors[cur] = color
    for i in adj[cur]:
        if colors[i] == color:
            check = False
            return
        if colors[i] == 0:
            dfs(i, -color)


k = int(input())
while k:
    v, e = map(int, input().split())
    adj = [[] for _ in range(v + 1)]
    colors = [0] * (v + 1)
    check = True
    for _ in range(e):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
    for i in range(1, v + 1):
        if not check:
            break
        if colors[i] == 0:
            dfs(i, 1)  # 처음을 1번컬러로 지정
    if check:
        print("YES")
    else:
        print("NO")
    k -= 1
