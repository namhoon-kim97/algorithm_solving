import sys

input = sys.stdin.readline

n = int(input())
d = [0] * 1001  # d[i] 는 2 * i 크기의 직사각형을 채우는 방법의 수를 10007로 나눈 나머지
d[0] = 1
d[1] = 1
for i in range(2, n + 1):
    d[i] = (d[i - 1] + d[i - 2]) % 10007
print(d[n])
