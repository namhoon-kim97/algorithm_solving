import sys

input = sys.stdin.readline
n, k = map(int, input().split())
a = list(map(int, input().split()))

plugins = []  # 현재 꽂혀져 있는 것들
ans = 0
for i in range(k):
    if a[i] in plugins:
        continue
    if len(plugins) < n:
        plugins.append(a[i])
        continue

    ans += 1
    idxs = []
    for j in plugins:
        try:
            idx = a[i + 1 :].index(j)
        except ValueError:
            idx = sys.maxsize
        idxs.append(idx)
    out_idx = idxs.index(max(idxs))
    del plugins[out_idx]
    plugins.append(a[i])

print(ans)
