import sys
from itertools import *

input = sys.stdin.readline


def found_sum(temp):
    ret = 0
    for i in range(n - 1):
        ret += abs(temp[i] - temp[i + 1])
    return ret


n = int(input())
a = list(map(int, input().split()))
max_num = -1
for i in permutations(a):
    max_num = max(max_num, found_sum(i))
print(max_num)
