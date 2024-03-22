import sys, math
from heapq import *

input = sys.stdin.readline

n = int(input())
max_h = []
min_h = []

for _ in range(n):
    x = int(input())
    if len(max_h) <= len(min_h):
        heappush(max_h, -x)
    else:
        heappush(min_h, x)
    if not len(min_h) == 0 and min_h[0] < -max_h[0]:
        heappush(min_h, -heappop(max_h))
        heappush(max_h, -heappop(min_h))
    print(-max_h[0])
