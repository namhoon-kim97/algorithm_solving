import sys

input = sys.stdin.readline
n = int(input())
a = [int(input()) for _ in range(n)]
d = [0] * (n)  # d[i] 는 i번째 까지 줄을 맞추는데 필요한 최소 이동 수

for i in range(0, n):
    d[i] = 1
    for j in range(0, i):
        if a[i] > a[j]:
            d[i] = max(d[i], d[j] + 1)

print(n -max(d))
