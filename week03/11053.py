import sys

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
d = [0] * (n + 1)  # d[i] 는 i번째까지 가장 긴 증가하는 부분수열의 길이

d[0] = 1
for i in range(1, n):
    d[i] = 1
    for j in range(i):
        if a[i] > a[j]:
            d[i] = max(d[i], d[j] + 1)

print(max(d))
