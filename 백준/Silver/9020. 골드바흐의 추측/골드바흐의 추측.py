import sys

input = sys.stdin.readline


a = [False, False] + [True] * (10001 - 1)
for i in range(2, 10001 + 1):
    if a[i]:
        for j in range(i * 2, 10001 + 1, i):
            a[j] = False

t = int(input())
for _ in range(t):
    n = int(input())
    min_num = 10000
    for i in range(n):
        if a[i] and a[n - i]:
            if min_num > abs(n - 2 * i):
                ans_a = i
                ans_b = n - i
                min_num = abs(n - i * 2)
    print(f"{ans_a} {ans_b}")
