import sys
from heapq import *

input = sys.stdin.readline
n = int(input())
h = []
for _ in range(n):
    a, b = map(int, input().split())
    heappush(h, (a, b))  # 데드라인, 컵라면 수

ans = 0
days = 1
h2 = []
while h:
    limit, value = heappop(h)
    if days <= limit:
        heappush(h2, value)
        days += 1
    else:
        if h2[0] < value:
            heappop(h2)
            heappush(h2, value)
while h2:
    ans += heappop(h2)
print(ans)
