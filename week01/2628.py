import sys

input = sys.stdin.readline

row, col = map(int, input().split())
n = int(input())
r = [0, col]
l = [0, row]

for _ in range(n):
    a, num = map(int, input().split())
    if a == 0:
        r.append(num)
    else:
        l.append(num)
r.sort()
l.sort()
max_x = 0
for i in range(len(r) - 1):
    max_x = max(max_x, r[i + 1] - r[i])
max_y = 0
for i in range(len(l) - 1):
    max_y = max(max_y, l[i + 1] - l[i])
print(max_x * max_y)
