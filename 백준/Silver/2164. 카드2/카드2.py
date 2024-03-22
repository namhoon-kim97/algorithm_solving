import sys
from collections import deque

input = sys.stdin.readline
deq = deque()

n = int(input())
if n == 1:
    print(1)
else:
    for i in range(1, n + 1):
        deq.append(i)
    while deq:
        deq.popleft()
        x = deq.popleft()
        if not deq:
            print(x)
            break
        deq.append(x)
