import sys


def find_min_diff(idx, sour, bitter):
    global min_diff
    if idx == N:
        if sour != 1:
            min_diff = min(min_diff, abs(sour - bitter))
        return

    find_min_diff(idx + 1, sour * taste_list[idx][0], bitter + taste_list[idx][1])
    find_min_diff(idx + 1, sour, bitter)


read = sys.stdin.readline
N = int(read().strip())

min_diff = sys.maxsize
taste_list = [list(map(int, read().strip().split())) for _ in range(N)]

find_min_diff(0, 1, 0)

print(min_diff)
