import sys


t = int(input())
for _ in range(t):
    n = int(input())
    cnt2 = 0
    cnt5 = 0
    i = 2
    j = 5
    while i <= n:
        cnt2 += n // i
        i *= 2
    while j <= n:
        cnt5 += n // j
        j *= 5

    print(min(cnt2, cnt5))
