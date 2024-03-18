from cmath import inf
import sys
from itertools import *

input = sys.stdin.readline


def solution(cur, cnt, cost):
    # 방문했거나 여기까지 못오거나 하면 return
    # 순회가 끝나면 return
    global min_cost
    if cnt == n and w[cur][st] > 0:
        min_cost = min(min_cost, cost + w[cur][st])
        return

    if cost >= min_cost:
        return

    for i in range(n):  # 다음 도시 i
        if vis[i] or w[cur][i] == 0:
            continue
        vis[i] = True
        solution(i, cnt + 1, cost + w[cur][i])
        vis[i] = False


n = int(input())
w = [list(map(int, input().split())) for _ in range(n)]

min_cost = inf
for st in range(n):
    vis = [False] * n
    vis[st] = True
    solution(st, 1, 0)  # 0번째 도시부터 출발
print(min_cost)
