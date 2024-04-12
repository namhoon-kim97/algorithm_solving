import sys

input = sys.stdin.readline


def solution(st, en, target):
    while st < en:
        mid = (st + en) // 2
        if target > a[mid]:
            st = mid + 1
        elif target <= a[mid]:
            en = mid
    if 0 <= st < n and a[st] == target:
        return st
    else:
        return -1


n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
a.sort()

for i in range(m):
    d = int(input())
    print(solution(0, n, d))
