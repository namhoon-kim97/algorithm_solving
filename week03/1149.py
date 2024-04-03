import sys

input = sys.stdin.readline
n = int(input())
adj = [list(map(int, input().split())) for _ in range(n)]

d = [
    [sys.maxsize] * (4) for _ in range(n + 1)
]  # d[i][j] 는 i번째 집을 j색으로 마무리 했을 때 최소비용

d[0][0] = adj[0][0]
d[0][1] = adj[0][1]
d[0][2] = adj[0][2]
for i in range(1, n):
    d[i][0] = min(d[i - 1][1], d[i - 1][2]) + adj[i][0]  # 빨간색 마무리
    d[i][1] = min(d[i - 1][0], d[i - 1][2]) + adj[i][1]  # 초록색 마무리
    d[i][2] = min(d[i - 1][0], d[i - 1][1]) + adj[i][2]  # 파란색 마무리

print(min(d[n - 1]))
