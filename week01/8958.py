import sys

n = int(input())
for i in range(n):
    a = list(sys.stdin.readline().rstrip())
    grade, weight = 0, 0
    for x in a:
        if x == "O":
            weight += 1
            grade += weight
        else:
            weight = 0

    print(grade)
