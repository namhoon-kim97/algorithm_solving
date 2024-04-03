import sys

input = sys.stdin.readline
a = input().strip()
n = len(a)
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
# print(*d, sep="\n")
dp = [0] * (n + 1)  # d[i]는 i번째 까지 왔을 때까지
dp[0] = 0

for i in range(1, n):
    if d[0][i]:
        dp[i] = 0
    else:
        dp[i] = dp[i - 1] + 1
        for j in range(1, i):
            if d[j][i] and dp[j - 1] + 1 < dp[i]:
                dp[i] = dp[j - 1] + 1

print(dp[n - 1] + 1)
