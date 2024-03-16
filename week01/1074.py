import sys

input = sys.stdin.readline


def solution(n, r, c):
    # 1사분면이면 n - 1,r,c 여기서 4사분면이면 n - 1, r + (2 ** n) * 3
    exp = 2 ** (n - 1)
    if n == 0:
        return 0
    if r < 2 ** (n - 1) and c < 2 ** (n - 1):
        return solution(n - 1, r, c)
    elif r < 2 ** (n - 1) and c >= 2 ** (n - 1):
        return solution(n - 1, r, c - (2 ** (n - 1))) + exp**2
    elif r >= 2 ** (n - 1) and c < 2 ** (n - 1):
        return solution(n - 1, r - (2 ** (n - 1)), c) + exp**2 * 2
    else:
        return solution(n - 1, r - (2 ** (n - 1)), c - (2 ** (n - 1))) + exp**2 * 3


n, r, c = map(int, input().split())

print(solution(n, r, c))
