import sys
from collections import deque

input = sys.stdin.readline
deq = deque()

n = int(input())

for i in range(1, n + 1):
    deq.append(i)

while len(deq) != 1:
    deq.popleft()
    deq.rotate(-1)

print(*deq)
