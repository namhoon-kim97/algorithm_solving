import sys

input = sys.stdin.readline
st = []
ans = []
n = int(input())
a = [int(input()) for _ in range(n)]
print(a)

cnt = 1
for i in a:
    while cnt <= i:
        st.append(cnt)
        ans.append("+")
        cnt += 1
    if i == st[-1]:
        st.pop()
        ans.append("-")
    else:
        print("NO")
        exit()

print(ans)
