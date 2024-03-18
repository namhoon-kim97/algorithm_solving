import sys

input = sys.stdin.readline


def merge(st, en):
    mid = (st + en) // 2
    aidx, bidx = st, mid
    if a[mid - 1] <= a[mid]:
        return  # 최선의 경우
    for i in range(st, en):
        if aidx >= mid:
            temp[i] = a[bidx]
            bidx += 1
        elif bidx >= en:
            temp[i] = a[aidx]
            aidx += 1
        elif a[aidx] <= a[bidx]:
            temp[i] = a[aidx]
            aidx += 1
        else:
            temp[i] = a[bidx]
            bidx += 1
    for i in range(st, en):
        a[i] = temp[i]


def merge_sort(st, en):
    if en - st == 1:
        return
    mid = (st + en) // 2
    merge_sort(st, mid)
    merge_sort(mid, en)
    merge(st, en)


n = int(input())
a = [int(input()) for _ in range(n)]
temp = [0] * n
merge_sort(0, n)
for x in a:
    print(x)
