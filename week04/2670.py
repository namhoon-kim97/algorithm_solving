import sys

input = sys.stdin.readline

n = int(input())
d = [float(input()) for _ in range(n)]

for i in range(1, n):
    d[i] = max(
        d[i], d[i] * d[i - 1]
    )  # i번째까지의 연속된 숫자곱, i번째 숫자를 곱해서 숫자가 작아지면 거기서 연속속성 초기화

print(f"{max(d):.3f}")
