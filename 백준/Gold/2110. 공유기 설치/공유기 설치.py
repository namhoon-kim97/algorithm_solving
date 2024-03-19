import sys
from itertools import *

input = sys.stdin.readline


def install_routers(length):
    # length이상 길이로 c개 놓아볼 수 있으면 True
    installed_cnt = 1
    last_installed = a[0]
    for i in range(1, len(a)):
        if a[i] - last_installed >= length:
            installed_cnt += 1
            last_installed = a[i]
            if installed_cnt >= c:
                return True
    return False


def solution(st, en):
    global ans
    if st > en:
        return
    mid = (st + en) // 2

    if install_routers(
        mid
    ):  # 가장 인접한 두 점의 거리를 mid로 공유기를 설치하는게 가능한가?
        ans = max(ans, mid)
        solution(mid + 1, en)
    else:
        solution(st, mid - 1)


n, c = map(int, input().split())
a = [int(input()) for _ in range(n)]
a.sort()
ans = -1
solution(0, sys.maxsize)
print(ans)
