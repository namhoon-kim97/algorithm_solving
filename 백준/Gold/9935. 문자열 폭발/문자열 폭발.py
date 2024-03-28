import sys

input = sys.stdin.readline
a = input().strip()
bomb = input().strip()

ans = []
for i in a:
    ans.append(i)
    if len(ans) >= len(bomb):
        if "".join(ans[-1 : -(len(bomb) + 1) : -1]) == bomb[::-1]:
            for j in range(len(bomb)):
                ans.pop()
if ans:
    print("".join(ans))
else:
    print("FRULA")
