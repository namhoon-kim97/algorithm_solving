import sys

input = sys.stdin.readline
t = int(input())
while t:
    n = int(input())
    coins = list(map(int, input().split()))
    m = int(input())
    d = [0] * (
        m + 1
    )  # d[i]는 금액 i를 만들 수 있는 경우의 수, d[i] = d[i - coin1] + d[i - coins2] (coin 2개면)
    d[0] = 1
    for coin in coins:
        for i in range(1, m + 1):
            if 0 <= i - coin <= m:
                d[i] += d[i - coin]
    print(d[m])
    t -= 1
