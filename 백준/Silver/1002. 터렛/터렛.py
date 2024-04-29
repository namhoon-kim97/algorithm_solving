from cmath import sqrt
import sys

input = sys.stdin.readline
t = int(input())
while t:
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
    if d == r1 + r2:
        print(1)
    elif d != 0 and d == abs(r1 - r2):
        print(1)
    elif abs(r1 - r2) < d < r1 + r2:
        print(2)
    elif d > r1 + r2 or d < abs(r1 - r2):
        print(0)
    else:
        print(-1)

    t -= 1
