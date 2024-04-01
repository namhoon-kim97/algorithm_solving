import sys

input = sys.stdin.readline


# def matrix_chain_order(p, i, j):
#     if i == j:
#         return 0
#     if memo[i][j]:
#         return memo[i][j]
#     min_count = float("inf")
#     for k in range(i, j):
#         cnt = (
#             matrix_chain_order(p, i, k)
#             + matrix_chain_order(p, k + 1, j)
#             + p[i - 1] * p[k] * p[j]
#         )
#         if cnt < min_count:
#             min_count = cnt
#     memo[i][j] = min_count
#     return min_count


n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

p = [a[0][0]] + [a[i][1] for i in range(n)]
d = [[float("inf")] * n for _ in range(n)]
for i in range(n):
    d[i][i] = 0

for i in range(1, n):
    for j in range(n - i):
        k = i + j
        for l in range(j, k):
            cost = d[j][l] + d[l + 1][k] + p[j] * p[l + 1] * p[k + 1]
            if cost < d[j][k]:
                d[j][k] = cost
print(d[0][n - 1])

# memo = [
#     [None] * (n + 1) for _ in range(n + 1)
# ]
# ans = matrix_chain_order(p, 1, n)
# print(ans)
