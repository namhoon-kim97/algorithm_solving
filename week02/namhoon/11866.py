import sys
from collections import deque

input = sys.stdin.readline
deq = deque()

n, k = map(int, input().split())

for i in range(1, n + 1):
    deq.append(i)
cnt = 0
ans = []
while deq:
    deq.rotate(-(k - 1))
    ans.append(deq.popleft())
print("<" + ", ".join(map(str, ans)) + ">")
