import sys

input = sys.stdin.readline


def ans_diff(ans):
    sour = 1
    bitter = 0
    for i in range(len(ans)):
        if ans[i]:
            sour *= ans[i][0]
            bitter += ans[i][1]
    return abs(sour - bitter)


def solution(cnt):
    global min_diff
    if cnt == n:
        return
    for i in range(n):
        if vis[i]:
            continue
        ans[cnt] = a[i]
        new_diff = ans_diff(ans)
        vis[i] = True
        min_diff = min(new_diff, min_diff)
        solution(cnt + 1)
        ans[cnt] = 0
        vis[i] = False


n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

min_diff = sys.maxsize
vis = [False] * n
ans = [0] * n
solution(0)
print(min_diff)
