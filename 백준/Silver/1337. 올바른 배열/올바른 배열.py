import sys

input = sys.stdin.readline
n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()

i = 0
l = 5
j = 0
max_cnt = -1
while j < n:
    cnt = 0
    i = j
    en = a[i] + l - 1
    while i < n and a[i] <= en:
        i += 1
        cnt += 1
    max_cnt = max(max_cnt, cnt)
    j += 1

print(l - max_cnt)
