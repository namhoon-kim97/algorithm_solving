import sys
from collections import deque

deq = deque()
input = sys.stdin.readline

n = int(input())
while n:
    a = input().split()
    if a[0] == "push":
        deq.append(a[1])
    elif a[0] == "front":
        if deq:
            print(deq[0])
        else:
            print(-1)
    elif a[0] == "back":
        if deq:
            print(deq[-1])
        else:
            print(-1)
    elif a[0] == "pop":
        if deq:
            temp = deq.popleft()
            print(temp)
        else:
            print(-1)
    elif a[0] == "empty":
        if deq:
            print(0)
        else:
            print(1)
    elif a[0] == "size":
        print(len(deq))
    n -= 1
