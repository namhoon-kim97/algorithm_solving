import sys

input = sys.stdin.readline
n = int(input())
towers = list(map(int, input().split()))

stack = []  # 스택: (탑의 인덱스, 탑의 높이)
answer = [0] * n  # 각 탑의 레이저 신호를 수신한 탑의 번호

for i in range(n):
    while stack and stack[-1][1] < towers[i]:
        stack.pop()
    if stack:
        answer[i] = stack[-1][0] + 1
    stack.append((i, towers[i]))

print(*answer)
