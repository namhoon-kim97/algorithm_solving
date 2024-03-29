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
# d[i] += d[i - coin] 인거는 같은데 cnt개를 다 돌면서 누적도 해줘야 함.

for coin, cnt in coins:
    for i in range(t, 0, -1):
        for j in range(1, cnt + 1):
            if 0 <= i - j * coin <= t:
                d[i] += d[i - j * coin]
print(d[t])
