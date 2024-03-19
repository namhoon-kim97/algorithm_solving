import sys

input = sys.stdin.readline


def distance(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2


def solution(a):
    if len(a) == 1:
        return float("inf")
    if len(a) == 2:
        return distance(a[0], a[1])

    a.sort(key=lambda x: x[0])
    mid = len(a) // 2
    left = a[:mid]
    right = a[mid:]
    min_dist_left = solution(left)
    min_dist_right = solution(right)
    min_dist_square = min(min_dist_left, min_dist_right)

    # 두 영역을 가로지르는 영역에서도 구해야함
    checks = []
    divide_x = a[mid][0]
    for i in range(len(a)):
        if (a[i][0] - divide_x) ** 2 <= min_dist_square:
            checks.append(a[i])
    checks.sort(key=lambda x: x[1])

    for i in range(len(checks)):
        cur = checks[i]
        for j in range(i + 1, len(checks)):
            compare = checks[j]
            if (compare[1] - cur[1]) ** 2 >= min_dist_square:
                break
            dist = distance(cur, compare)
            min_dist_square = min(min_dist_square, dist)

    return min_dist_square


n = int(input())

dots = [list(map(int, input().split())) for _ in range(n)]

print(solution(dots))
