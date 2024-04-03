import sys

input = sys.stdin.readline
n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]
d = [0] * (k + 1)
d[0] = 1

for coin in coins:
    for i in range(1, k + 1):
        if coin <= i:
            d[i] += d[i - coin]
    # print(*d)

# print(d[k])
print(d[k])
