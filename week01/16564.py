import sys

input = sys.stdin.readline


def possible(mid):
    temp = k
    for level in levels:
        if mid > level:
            temp -= mid - level
    if temp < 0:
        return False
    else:
        return True


def solution(st, en):
    global ans
    if st > en:
        return
    mid = (st + en) // 2
    if possible(mid):
        ans = max(ans, mid)
        solution(mid + 1, en)
    else:
        solution(st, mid - 1)


n, k = map(int, input().split())
levels = [int(input()) for _ in range(n)]
ans = -1
solution(0, sys.maxsize)
print(ans)
