import sys
from heapq import *

input = sys.stdin.readline

n = int(input())
h = []
sum = 0
for i in range(n):
    x = int(input())
    heappush(h, x)

while len(h) > 1:
    x = heappop(h)
    y = heappop(h)
    heappush(h, x + y)
    sum += (x + y)
print(sum)
