import sys

input = sys.stdin.readline
n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
vis = [False] * (n + 1)
st = []
cnt = 0
for i in range(1, n + 1):
    if vis[i]:
        continue
    st.append(i)
    cnt += 1
    while st:
        cur = st.pop()
        if vis[cur]:
            continue
        vis[cur] = True
        for i in adj[cur]:
            if not vis[i]:
                st.append(i)
print(cnt)
