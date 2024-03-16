t = int(input())
for i in range(t):
    r, s = input().split()
    r = int(r)
    ans = ""
    for x in s:
        for i in range(r):
            ans += x
    print(ans)
