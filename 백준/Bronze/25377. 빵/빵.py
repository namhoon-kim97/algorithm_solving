import sys

input = sys.stdin.readline

n = int(input())
lines = []
cnt = sys.maxsize
for _ in range(n):
    a, b = map(int, input().split())
    # lines.append((a, b))
    if a <= b:
        cnt = min(cnt, a + (b - a))
if cnt != sys.maxsize:
    print(cnt)
else:
    print(-1)
