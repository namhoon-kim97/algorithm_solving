import sys

input = sys.stdin.readline
n, k = map(int, input().split())
a = []
for _ in range(n):
    a.append(int(input()))

cnt = 0
ret = 0
for j in a[::-1]:
    cnt += k // j
    k %= j
print(cnt)
