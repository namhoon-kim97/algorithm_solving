import sys
from cmath import inf

input = sys.stdin.readline


def compute(cnt, num):
    global add, sub, mul, div, max_num, min_num
    if cnt == n:
        max_num = max(max_num, num)
        min_num = min(min_num, num)
    else:
        if add > 0:
            add -= 1
            compute(cnt + 1, num + a[cnt])
            add += 1
        if sub > 0:
            sub -= 1
            compute(cnt + 1, num - a[cnt])
            sub += 1
        if mul > 0:
            mul -= 1
            compute(cnt + 1, num * a[cnt])
            mul += 1
        if div > 0:
            div -= 1
            compute(cnt + 1, int(num / a[cnt]))
            div += 1


n = int(input())
a = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())
max_num = -(inf)
min_num = inf

compute(1, a[0])

print(max_num)
print(min_num)
