import sys

input = sys.stdin.readline


def found_in_a(target, st, en):
    if st >= en:
        return False
    mid = (st + en) // 2
    if a[mid] == target:
        return True
    if target < a[mid]:
        return found_in_a(target, st, mid)
    else:
        return found_in_a(target, mid + 1, en)


n = int(input())
a = list(map(int, input().split()))
a.sort()
m = int(input())
targets = list(map(int, input().split()))

for target in targets:
    if found_in_a(target, 0, len(a)):
        print(1)
    else:
        print(0)
