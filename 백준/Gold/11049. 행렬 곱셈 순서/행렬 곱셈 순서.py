import sys

input = sys.stdin.readline


def matrix_chain_order(p, i, j):
    if i == j:
        return 0
    if memo[i][j]:
        return memo[i][j]
    min_count = float("inf")
    for k in range(i, j):
        cnt = (
            matrix_chain_order(p, i, k)
            + matrix_chain_order(p, k + 1, j)
            + p[i - 1] * p[k] * p[j]
        )
        if cnt < min_count:
            min_count = cnt
    memo[i][j] = min_count
    return min_count


n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

p = [a[0][0]] + [a[i][1] for i in range(n)]
memo = [
    [None] * (n + 1) for _ in range(n + 1)
]  # 메모이제이션을 위한 2차원 리스트 초기화
ans = matrix_chain_order(p, 1, n)
print(ans)
