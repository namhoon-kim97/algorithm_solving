import sys

x, y, w, h = map(int, sys.stdin.readline().split())

a = min(x, w - x)
b = min(y, h - y)
print(min(a, b))
