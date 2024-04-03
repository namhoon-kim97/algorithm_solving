import sys
from heapq import *

input = sys.stdin.readline

n = int(input())
h = []
for i in range(n):
    x = int(input())
    if x != 0:
        heappush(h, -x)
    elif x == 0 and not h:
        print(0)
    else:
        print(-h[0])
        heappop(h)
