import sys

input = sys.stdin.readline


def multiply(a, b):
    if b == 0:
        return 1
    elif b == 1:
        return a % c
    else:
        half = multiply(a, b // 2)
        if b % 2 == 0:
            return half * half % c
        else:
            return half * half * a % c


a, b, c = map(int, input().split())
print(multiply(a, b))
