import sys

input = sys.stdin.readline
n, d, k, c = map(int, input().split())

a = [int(input()) for _ in range(n)]
a += a[: k - 1]
d = {c: 1}
res = 0

for i in range(k):
    d[a[i]] = d.get(a[i], 0) + 1
print(d)
res = max(res, len(d))

for i in range(k, len(a)):
    d[a[i]] = d.get(a[i], 0) + 1
    d[a[i - k]] -= 1
    if d[a[i - k]] == 0:
        del d[a[i - k]]
    print(d)
    res = max(res, len(d))

print(res)
