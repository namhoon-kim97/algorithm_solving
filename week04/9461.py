import sys

input = sys.stdin.readline
t = int(input())
while t:
    n = int(input())
    if n < 3:
        print(1)
        t -= 1
        continue
    d = [0] * (n + 1)
    d[1] = 1
    d[2] = 1
    d[3] = 1

    for i in range(4, n + 1):
        d[i] = d[i - 2] + d[i - 3]
    print(d[n])
    t -= 1
