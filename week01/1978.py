import sys


def found_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


n = int(input())
cnt = 0

a = list(map(int, sys.stdin.readline().split()))

for x in a:
    if found_prime(x):
        cnt += 1
print(cnt)
