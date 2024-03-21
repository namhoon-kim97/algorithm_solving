import sys

input = sys.stdin.readline
n = int(input())

print((n + 1) * n // 2)
print(int(pow((n + 1) * n // 2, 2)))
sum = 0
for i in range(1, n + 1):
    sum += pow(i, 3)
print(sum)
