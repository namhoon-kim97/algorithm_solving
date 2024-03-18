from itertools import *
import sys

input = sys.stdin.readline

a = [int(input()) for _ in range(9)]
a.sort()
b = combinations(a, 7)
for i in b:
    if sum(i) == 100:
        print(*i, sep="\n")
        break
