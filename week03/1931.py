import sys

input = sys.stdin.readline
n = int(input())
works = []
for _ in range(n):
    a, b = map(int, input().split())
    works.append((b, a))

works.sort()
cnt = 0
en = -1
st = -1
for i in range(len(works)):
    if works[i][1] >= en:
        cnt += 1
        en = works[i][0]
print(cnt)
