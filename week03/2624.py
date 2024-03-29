import sys

input = sys.stdin.readline
t = int(input())
k = int(input())
coins = []
for i in range(k):
    a, b = map(int, input().split())
    coins.append((a, b))  # 동전 금액, 개수
d = [0] * (t + 1)  # d[i] 는 금액 i를 만들 수 있는 경우의 수
d[0] = 1
for coin, cnt in coins:
    for money in range(t, 0, -1):
        for i in range(1, cnt + 1):
            if money - coin * i >= 0:
                d[money] += d[money - coin * i]
print(d[t])
