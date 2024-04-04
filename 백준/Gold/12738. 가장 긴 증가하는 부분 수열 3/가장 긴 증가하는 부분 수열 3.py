import sys

input = sys.stdin.readline


def search(target, lis):
    st, en = 0, len(lis) - 1
    while st < en:
        mid = (st + en) // 2
        if lis[mid] == target:
            return mid

        elif lis[mid - 1] < target < lis[mid]:
            return mid
        elif target < lis[mid]:
            en = mid - 1
        else:
            st = mid + 1
    return st


n = int(input())
a = list(map(int, input().split()))
lis = [sys.maxsize] * (n + 1)
lis = [a[0]]

for i in range(1, n):
    target = a[i]
    if lis[-1] < target:
        lis.append(target)
    else:
        idx = search(target, lis)
        lis[idx] = target

print(len(lis))
