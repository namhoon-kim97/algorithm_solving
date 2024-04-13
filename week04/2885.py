import sys

input = sys.stdin.readline
k = int(input())
min_num = 1
while k > min_num:
    min_num *= 2

cnt = 0
ans = min_num
if k == min_num:
    print(min_num, cnt)
else:
    while k:
        x = min_num // 2
        if x <= k:
            k -= x
        cnt += 1
        min_num //= 2
    print(ans, cnt)
