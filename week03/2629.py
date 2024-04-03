import sys

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
k = int(input())
targets = list(map(int, input().split()))

# d[i][w] i번째 추까지 고려했을 때 w만큼의 무게를 측정할 수 있냐
max_weight = 40001
d = [[False] * (2 * max_weight) for _ in range(n + 1)]
d[0][max_weight] = 1
# d = set([0])
# for i in a:
#     temp = set()
#     for j in d:
#         temp.add(i + j)
#         temp.add(abs(i - j))
#     d.update(temp)
for i in range(1, n + 1):
    for j in range(2 * max_weight):
        if d[i - 1][j]:
            d[i][j] = True
            if j + a[i - 1] < 2 * max_weight:
                d[i][j + a[i - 1]] = True
            if j - a[i - 1] >= 0:
                d[i][j - a[i - 1]] = True


for i in targets:
    if d[n][i + max_weight]:
        print("Y", end=" ")
    else:
        print("N", end=" ")
