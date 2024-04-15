import sys

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))

cnt = 0
cur = 0
ans = 0
for i in range(len(a)):
    if cur < a[i]:
        cur = a[i]
        ans = max(ans, cnt)
        cnt = 0
    else:
        cnt += 1
print(max(ans, cnt))
