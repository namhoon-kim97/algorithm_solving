import sys

input = sys.stdin.readline
n = int(input())
d = [0] * (n + 1)  # d[i] i를 0

if n % 2 == 0:
    print("CY")
else:
    print("SK")
