import sys

input = sys.stdin.readline


def solution(st, en):
    if en - st < 2:
        return

    third = (en - st) // 3
    for i in range(st + third, st + third * 2):
        s[i] = " "
    solution(st, st + third)
    solution(st + third * 2, en)


while True:
    try:
        n = int(input())
        s = ["-"] * (3**n)
        solution(0, 3**n)
        print("".join(s))
    except:
        break
