import sys

input = sys.stdin.readline
t = int(input())
while t:
    n = int(input())
    applicants = [list(map(int, input().split())) for _ in range(n)]
    applicants.sort()
    cnt = 1

    st = applicants[0][0]
    en = applicants[0][1]
    for i in range(1, len(applicants)):
        if applicants[i][0] < st or applicants[i][1] < en:
            cnt += 1
            st = applicants[i][0]
            en = applicants[i][1]
    print(cnt)
    t -= 1
