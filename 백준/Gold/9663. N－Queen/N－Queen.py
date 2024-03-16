import sys

input = sys.stdin.readline


def solution(cur):
    if cur == n:
        global cnt
        cnt += 1
        return

    for i in range(n):
        if not flag_a[cur + i] and not flag_b[cur - i + n - 1] and not vis_col[i]:
            vis_col[i] = True
            flag_a[cur + i] = True
            flag_b[cur - i + n - 1] = True
            solution(cur + 1)
            vis_col[i] = False
            flag_a[cur + i] = False
            flag_b[cur - i + n - 1] = False


cnt = 0
n = int(input())
vis_col = [False] * n  # 세로
flag_a = [False] * n * 2  # 주대각선
flag_b = [False] * n * 2  # 부대각선
solution(0)
print(cnt)
