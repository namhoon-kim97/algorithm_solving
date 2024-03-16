import sys

input = sys.stdin.readline

n = int(input())
ans = [0] * 10001
for i in range(n):
    temp = int(input())
    ans[temp] += 1


for i in range(10001):
    if ans[i]:
        for j in range(ans[i]):
            print(i)
