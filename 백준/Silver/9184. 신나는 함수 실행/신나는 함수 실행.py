import sys

input = sys.stdin.readline


def w(a, b, c):
    if memo[a + num][b + num][c + num]:
        return memo[a + num][b + num][c + num]

    if a <= 0 or b <= 0 or c <= 0:
        return 1
    if a > 20 or b > 20 or c > 20:
        memo[a + num][b + num][c + num] = w(20, 20, 20)
        return memo[a + num][b + num][c + num]

    if a < b and b < c:
        memo[a + num][b + num][c + num] = (
            w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
        )
        return memo[a + num][b + num][c + num]

    memo[a + num][b + num][c + num] = (
        w(a - 1, b, c)
        + w(a - 1, b - 1, c)
        + w(a - 1, b, c - 1)
        - w(a - 1, b - 1, c - 1)
    )
    return memo[a + num][b + num][c + num]

memo = [[[0] * (101) for _ in range(101)] for _ in range(101)]
num = 50
while True:
    a, b, c = map(int, input().split())
    if a == -1 and b == -1 and c == -1:
        break
    
    # d = [[[0] * (101) for _ in range(101)] for _ in range(101)]
    # for i in range(a + num):
    #     for j in range(b + num):
    #         for k in range(c + num):

    print(f"w({a}, {b}, {c}) = {w(a,b,c)}")
