import sys

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
m = int(input())
d = [
    [False] * (n) for _ in range(n)
]  # d[i][j] 는 i번째 부터 j번째 까지 팰린드롬이면 True


for i in range(n - 1, -1, -1):
    for j in range(i, n):
        if a[i] == a[j]:
            if j - i >= 2:
                if d[i + 1][j - 1]:
                    d[i][j] = True
            else:
                d[i][j] = True


for _ in range(m):
    a, b = map(int, input().split())
    if d[a - 1][b - 1]:
        print(1)
    else:
        print(0)
