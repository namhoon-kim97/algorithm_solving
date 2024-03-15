import sys

n, x = map(int, (input().split()))

a = list(map(int, sys.stdin.readline().split()))
b = []
for i in a:
    if i < x:
        b.append(i)
print(*b)
