import sys

input = sys.stdin.readline


def find_in_two(num):
    st = 0
    en = len(two) - 1
    while st < en:
        mid = (st + en) // 2
        if two[mid] > num:
            en = mid - 1
        elif two[mid] < num:
            st = mid + 1
        else:
            return True
    return False


n = int(input())
u = [int(input()) for _ in range(n)]
u.sort()
two = []
for i in range(0, n):
    for j in range(i, n):
        two.append(u[i] + u[j])
two.sort()
ans = 0
for i in range(n - 1, 0, -1):
    for j in range(0, i):
        if find_in_two(u[i] - u[j]):
            print(u[i])
            exit()
        else:
            continue
