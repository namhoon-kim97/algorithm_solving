import sys

input = sys.stdin.readline

a = [int(input()) for _ in range(9)]
ans = [0] * 9
a.sort()

for i in range(8):
    temp = a
    sub_i = temp.pop(i)
    for j in range(i, 8):
        sub_j = temp.pop(j)
        if sum(temp) == 100:
            print(*temp, sep="\n")
            exit()
        temp.insert(j, sub_j)
    temp.insert(i, sub_i)
