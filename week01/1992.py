import sys

input = sys.stdin.readline


def check_uniform_number(st_x, st_y, en_x, en_y):
    temp = a[st_x][st_y]
    for i in range(st_x, en_x):
        for j in range(st_y, en_y):
            if a[i][j] != temp:
                return False
    return True


def solution(st_x, st_y, en_x, en_y):
    global res
    if en_x - st_x == 1 or check_uniform_number(st_x, st_y, en_x, en_y):
        if a[st_x][st_y] == "1":
            res += "1"
        else:
            res += "0"
        return
    res += "("
    mid_x = (st_x + en_x) // 2
    mid_y = (st_y + en_y) // 2
    solution(st_x, st_y, mid_x, mid_y)
    solution(st_x, mid_y, mid_x, en_y)
    solution(mid_x, st_y, en_x, mid_y)
    solution(mid_x, mid_y, en_x, en_y)
    res += ")"


n = int(input())
a = [input().strip() for _ in range(n)]
res = ""
solution(0, 0, n, n)
print(res)
