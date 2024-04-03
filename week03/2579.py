import sys

input = sys.stdin.readline
n = int(input())

stairs = [int(input()) for _ in range(n)]
if n == 1:
    print(stairs[0])
    exit()
d = [
    [0] * (4) for _ in range(n + 1)
]  # d[i][j] 는 현재까지 j개의 계단을 연속해서 밟고 i번째 계단에 올라섰을때 점수 최댓값
# d[i][1] = max(d[i - 2][1], d[i-2][2]) + a[i - 1]
# d[i][2] = max(d[i-1][1]) + a[i- 1]
d[1][1] = stairs[0]
d[1][2] = 0
d[2][1] = stairs[1]
d[2][2] = d[1][1] + stairs[1]
for i in range(3, n + 1):
    d[i][1] = max(d[i - 2][1], d[i - 2][2]) + stairs[i - 1]
    d[i][2] = d[i - 1][1] + stairs[i - 1]

print(max(d[n][1], d[n][2]))
