import sys

input = sys.stdin.readline


def count_cut(length):
    return sum(x // length for x in a)


def solution(st, en):
    global ans
    if st > en:
        return
    mid = (st + en) // 2
    if mid == 0:
        return
    cutted = count_cut(mid)
    if cutted >= n:
        ans = max(mid, ans)
        solution(mid + 1, en)  # mid + 1안하면 무한 재귀에 빠짐
    else:
        solution(st, mid - 1)


k, n = map(int, input().split())
a = [int(input()) for _ in range(k)]
ans = 0

solution(1, 2147483647)
print(ans)
