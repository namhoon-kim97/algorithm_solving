import sys
from heapq import *

input = sys.stdin.readline

n = int(input())
lines = []
for _ in range(n):
    x, y = map(int, input().split())
    if y > x:
        lines.append((x, y))
    else:
        lines.append((y, x))
dist = int(input())
lines.sort(key=lambda x: x[1])
ans = 0
h = []

for st, en in lines:
    if en - st > dist:
        continue
    heappush(h, st)
    while en - h[0] > dist:
        heappop(h)
    ans = max(ans, len(h))
print(ans)
