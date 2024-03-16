import sys

input = sys.stdin.readline

n = int(input())
if n < 100:
    print(n)
else:
    cnt = 99
    for x in range(100, n + 1):
        sub = int(str(x)[1]) - int(str(x)[0])
        flag = True
        for i in range(1, len(str(x)) - 1):
            if sub != int(str(x)[i + 1]) - int(str(x)[i]):
                flag = False
                break
        if flag:
            cnt += 1
    print(cnt)
