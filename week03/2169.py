import sys

input = sys.stdin.readline
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
d = [[0] * (m) for _ in range(n)]  # d[i][j]는 i,j까지 움직였을 때 최대 가치

d[0][0] = board[0][0]
for i in range(1, m):
    d[0][i] = d[0][i - 1] + board[0][i]

for i in range(1, n):
    ltemp = board[i][:]
    rtemp = board[i][:]

    for j in range(m):
        if j == 0:
            ltemp[j] += d[i - 1][j]
        else:
            ltemp[j] += max(d[i - 1][j], ltemp[j - 1])
    for j in range(m - 1, -1, -1):
        if j == m - 1:
            rtemp[j] += d[i - 1][j]
        else:
            rtemp[j] += max(d[i - 1][j], rtemp[j + 1])
    for j in range(m):
        d[i][j] = max(ltemp[j], rtemp[j])
print(d[n - 1][m - 1])
