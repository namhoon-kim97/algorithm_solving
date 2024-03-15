import sys

n = int(input())

a = [sys.stdin.readline().rstrip() for i in range(n)]

for i in a:
    x, y = map(int, i.split())
    print(x + y)
