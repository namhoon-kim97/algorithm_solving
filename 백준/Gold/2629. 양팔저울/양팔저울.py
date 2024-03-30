import sys

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
k = int(input())
targets = list(map(int, input().split()))

# d[i][w] i번째 추까지 고려했을 때 w만큼의 무게를 측정할 수 있냐
# d = [[False] * 40000 for _ in range(n + 1)]
d = set([0])
for i in a:
    temp = set()
    for j in d:
        temp.add(i + j)
        temp.add(abs(i - j))
    d.update(temp)

for i in targets:
    if i in d:
        print("Y", end=" ")
    else:
        print("N", end=" ")
