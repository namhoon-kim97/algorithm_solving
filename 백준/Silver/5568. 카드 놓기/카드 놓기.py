import sys

input = sys.stdin.readline


def solution(cnt):
    if cnt == k:
        temp = ""
        for i in range(k):
            temp += str(b[i])
        ans.append(temp)
        return

    for i in range(n):
        if not vis[i]:
            vis[i] = True
            b[cnt] = a[i]
            solution(cnt + 1)
            vis[i] = False


n = int(input())
k = int(input())

vis = [False] * n
a = [int(input()) for _ in range(n)]
b = [0] * n
ans = []
solution(0)
unique = set(ans)
print(len(unique))
