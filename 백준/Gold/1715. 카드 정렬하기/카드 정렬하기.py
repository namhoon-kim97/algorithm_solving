import sys, math
from heapq import *

input = sys.stdin.readline

n = int(input())
h = []
sum = 0
for i in range(n):
    x = int(input())
    heappush(h, x)

cnt = 0
while len(h) > 1:
    x = heappop(h)
    y = heappop(h)
    heappush(h, x + y)
    cnt += x + y
print(cnt)
