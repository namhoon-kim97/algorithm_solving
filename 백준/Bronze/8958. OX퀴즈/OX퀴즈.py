import sys

n = int(input())
for i in range(n):
    a = list(sys.stdin.readline().rstrip())
    grade = 0
    j = 0
    while j < len(a):
        weight = 1
        flag = True
        while j < len(a) and a[j] == "O":
            grade += weight
            weight += 1
            j += 1
            flag = False
        if flag:
            j += 1

    print(grade)
