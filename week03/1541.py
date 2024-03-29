import sys

input = sys.stdin.readline


def calculate(exp):
    exp = exp.split("+")
    ret = 0
    for i in exp:
        ret += int(i)
    return ret


a = input().strip().split("-")

ans = calculate(a[0])
for i in range(1, len(a)):
    ans -= calculate(a[i])
print(ans)
