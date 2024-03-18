import sys

input = sys.stdin.readline


def find_length(height):
    return sum([x - height for x in heights if x - height > 0])


def solution(st, en):
    global ans
    if st > en:
        return
    mid = (st + en + 1) // 2
    length = find_length(mid)  # 길이 mid일 때 나오는 나무의 길이

    if length >= m:
        ans = max(ans, mid)
        solution(mid + 1, en)
    elif length < m:
        solution(st, mid - 1)


n, m = map(int, input().split())
heights = list(map(int, input().split()))
ans = 0
solution(0, sys.maxsize)
print(ans)
