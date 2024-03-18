import sys

input = sys.stdin.readline


def check_uniform_color(st_x, st_y, en_x, en_y):
    temp = a[st_x][st_y]
    for i in range(st_x, en_x):
        for j in range(st_y, en_y):
            if a[i][j] != temp:
                return False
    return True


def solution(st_x, st_y, en_x, en_y):
    global wcnt, bcnt
    if en_x - st_x == 1 or check_uniform_color(st_x, st_y, en_x, en_y):
        if a[st_x][st_y] == 0:
            wcnt += 1
        else:
            bcnt += 1
        return
    mid_x = (st_x + en_x) // 2
    mid_y = (st_y + en_y) // 2
    solution(st_x, st_y, mid_x, mid_y)
    solution(mid_x, st_y, en_x, mid_y)
    solution(st_x, mid_y, mid_x, en_y)
    solution(mid_x, mid_y, en_x, en_y)


n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
bcnt = 0
wcnt = 0

solution(0, 0, n, n)
print(wcnt, bcnt, sep="\n")
