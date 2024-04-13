import sys

input = sys.stdin.readline


n = int(input())
a = list(map(int, input().split()))
k = int(input())

idx = n // k
b = []
for i in range(0, n, idx):
    b = a[i : i + idx]
    b.sort()
    print(*b, end=" ")
