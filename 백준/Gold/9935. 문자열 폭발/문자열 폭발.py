import sys

input = sys.stdin.readline
a = input().strip()
bomb = input().strip()

ans = []
for i in a:
    ans.append(i)
    if len(ans) >= len(bomb) and "".join(ans[len(ans) - len(bomb) :]) == bomb:
        for j in range(len(bomb)):
            ans.pop()
if ans:
    print("".join(ans))
else:
    print("FRULA")
