import sys

input = sys.stdin.readline


def lower_bound(st, en, num):
    if st > en:
        return st
    mid = (st + en) // 2
    if a[mid] >= num:
        return lower_bound(st, mid - 1, num)
    else:
        return lower_bound(mid + 1, en, num)


n = int(input())
a = list(map(int, input().split()))
b = [x for x in a]
a = list(set(a))
a.sort()
# x보다 작은 값이 몇개가 있는지 -> x의 lower_bound값
ans = []
for i in b:
    ans.append(lower_bound(0, len(a), i))
print(*ans)
