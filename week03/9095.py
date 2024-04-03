import sys

input = sys.stdin.readline

d = [0] * (11)  # d[i] 는 i를 1,2,3의 합으로 나타내는 방법의 수
d[1] = 1
d[2] = 2
d[3] = 4
for i in range(4, 11):
    d[i] = d[i - 1] + d[i - 2] + d[i - 3]


t = int(input())
while t:
    n = int(input())
    print(d[n])
    t -= 1
