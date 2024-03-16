import sys

input = sys.stdin.readline


def hanoi(n, st, temp, en):
    if n == 0:
        return
    hanoi(n - 1, st, en, temp)
    print(f"{st} {en}")
    hanoi(n - 1, temp, st, en)


n = int(input())
print(2**n - 1)
if n <= 20:
    hanoi(n, 1, 2, 3)
