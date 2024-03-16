import sys

c = int(input())
for i in range(c):
    a = list(map(int, sys.stdin.readline().split()))
    student_n = a[0]
    grade_sum = sum(a[1::])
    average = grade_sum / student_n
    cnt = 0
    for x in a[1::]:
        if x > average:
            cnt += 1
    print("{:.3f}%".format(cnt / student_n * 100))
