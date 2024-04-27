import sys

input = sys.stdin.readline


def solution(num):
    ret = ""
    for x in str(num):
        if x == "0":
            ret += "zero "
        if x == "1":
            ret += "one "
        if x == "2":
            ret += "two "
        if x == "3":
            ret += "three "
        if x == "4":
            ret += "four "
        if x == "5":
            ret += "five "
        if x == "6":
            ret += "six "
        if x == "7":
            ret += "sevne "
        if x == "8":
            ret += "eight "
        if x == "9":
            ret += "nine "
    return ret.strip()


m, n = map(int, input().split())


a = [x for x in range(m, n + 1)]
b = {}
for i in a:
    b[i] = solution(i)
b = sorted(b.items(), key=lambda item: item[1])

cnt = 0
for i, j in b:
    cnt += 1
    print(i, end=" ")
    if cnt == 10:
        cnt = 0
        print()
