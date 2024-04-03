import sys

input = sys.stdin.readline
n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]
d = [sys.maxsize] * (
    k + 1
)  # d[i] 는 금액 i를 만드는 최소 경우의 수, d[i] = min(d[i - coin1], d[i - coin2]) + 1
d[0] = 0
for coin in coins:
    for i in range(coin, k + 1):
        d[i] = min(d[i], d[i - coin] + 1)

if d[k] < sys.maxsize:
    print(d[k])
else:
    print(-1)
