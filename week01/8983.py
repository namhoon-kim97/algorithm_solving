import sys

input = sys.stdin.readline

# 동물 x,y를 사대 mid에서 잡을 수 있으면 cnt


def solution(x, y):
    global cnt
    left = 0
    right = len(shots) - 1
    while left <= right:
        mid = (left + right) // 2
        if abs(shots[mid] - x) + y <= l:
            cnt += 1
            return
        else:
            if shots[mid] < x:
                left = mid + 1
            else:
                right = mid - 1


m, n, l = map(int, input().split())
shots = list(map(int, input().split()))
animals = [list(map(int, input().split())) for _ in range(n)]
shots.sort()
cnt = 0

for x, y in animals:
    solution(x, y)
print(cnt)
