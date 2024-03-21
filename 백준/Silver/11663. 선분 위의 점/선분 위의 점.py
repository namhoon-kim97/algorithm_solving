import sys

input = sys.stdin.readline


def lower_bound(target):
    st, en = 0, n - 1
    while st <= en:
        mid = (st + en) // 2
        if a[mid] >= target:
            en = mid - 1
        else:
            st = mid + 1
    return st


def upper_bound(target):
    st, en = 0, n - 1
    while st <= en:
        mid = (st + en) // 2
        if a[mid] <= target:
            st = mid + 1
        else:
            en = mid - 1
    return en


n, m = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
for i in range(m):
    x, y = map(int, input().split())
    x_idx = lower_bound(x)
    y_idx = upper_bound(y)
    # y_idx에서 x_idx를 빼고, 1을 더해야 선분 위의 점의 개수가 된다.
    print(y_idx - x_idx + 1)
