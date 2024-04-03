import sys

input = sys.stdin.readline
s = input().strip()
n = int(input())
a = [input().strip() for _ in range(n)]

d = [False] * (len(s) + 1)  # d[i] 는 S의 i번째 까지 만들 수 있냐
d[len(s)] = True

for i in range(len(s) - 1, -1, -1):
    for word in a:
        if word == s[i : i + len(word)] and d[i + len(word)]:
            d[i] = True
if d[0]:
    print(1)
else:
    print(0)
