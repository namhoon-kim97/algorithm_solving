import sys

input = sys.stdin.readline
n, k = map(int, input().split())
a = [0] + [list(map(int, input().split())) for _ in range(n)]

d = [
    [0] * (k + 1) for _ in range(n + 1)
]  # d[i][w] i번째까지 고려했을 때 w만큼의 가치를 측정할 수 있냐
for i in range(1, n + 1):
    for j in range(1, k + 1):
        if a[i][0] > j:
            d[i][j] = d[i - 1][j]
        elif a[i][0] <= j:
            d[i][j] = max(d[i - 1][j - a[i][0]] + a[i][1], d[i - 1][j])
#print(*d, sep="\n")
print(d[n][k])
