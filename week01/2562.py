import sys

a = [int(sys.stdin.readline()) for i in range(9)]

max_num = 0
max_i = 0
for i in range(len(a)):
    if a[i] > max_num:
        max_num = a[i]
        max_i = i

print(max_num)
print(max_i + 1)
