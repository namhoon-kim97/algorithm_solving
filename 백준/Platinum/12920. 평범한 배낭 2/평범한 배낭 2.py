import sys

input = sys.stdin.readline
n, k = map(int, input().split())
a = []

for _ in range(n):
    w, v, c = map(int, input().split())
    i = 1
    while i <= c:
        a.append((w * i, v * i))
        c -= i
        i *= 2
    if c > 0:
        a.append((w * c, v * c))

d = [0] * (k + 1)
for w, v in a:
    for j in range(k, w - 1, -1):
        d[j] = max(d[j], d[j - w] + v)
print(d[k])
