import sys

input = sys.stdin.readline


def multiply(a, b):
    row = len(a)
    col = len(b[0])
    res = [[0 for _ in range(col)] for _ in range(row)]

    for i in range(row):
        for j in range(col):
            for k in range(len(a[0])):
                res[i][j] += a[i][k] * b[k][j] % 1000
                res[i][j] %= 1000
    return res


def power(a, b):
    if b == 0:
        return [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    else:
        half = power(a, b // 2)
        if b % 2 == 0:
            return multiply(half, half)
        else:
            return multiply(multiply(half, half), a)


n, b = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

a = power(a, b)
for x in a:
    print(*x)
