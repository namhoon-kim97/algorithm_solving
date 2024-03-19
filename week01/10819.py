import sys
from itertools import *

input = sys.stdin.readline


def found_sum(temp):
    ret = 0
    for i in range(n - 1):
        ret += abs(temp[i] - temp[i + 1])
    return ret


def solution(a, st=0):
    global max_num
    if st == len(a) - 1:
        max_num = max(max_num, found_sum(a))
        return
    for i in range(len(a)):
        a[st], a[i] = a[i], a[st]
        solution(a, st + 1)
        a[st], a[i] = a[i], a[st]


n = int(input())
a = list(map(int, input().split()))
max_num = -1
# for i in permutations(a):
#     max_num = max(max_num, found_sum(i))
solution(a)
print(max_num)
