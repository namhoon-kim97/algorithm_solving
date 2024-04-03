import sys

input = sys.stdin.readline
n, m = map(int, input().split())
stones = [int(input()) for _ in range(m)]
d = [
    [100001] * (int((2 * n) ** 0.5) + 2) for _ in range(n + 1)
]  # d[i][j] 는 1번돌에서 i번째 돌까지 j의 속도로 왔을 때 최소 회수


d[1][0] = 0
for i in range(2, n + 1):
    if i in stones:
        continue
    for j in range(1, int((2 * i) ** 0.5) + 1):
        d[i][j] = min(d[i - j][j - 1], d[i - j][j], d[i - j][j + 1]) + 1

ans = min(d[n])
if ans >= sys.maxsize:
    print(-1)
else:
    print(ans)
