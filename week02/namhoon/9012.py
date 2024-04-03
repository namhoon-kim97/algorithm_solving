import sys

input = sys.stdin.readline
k = int(input())

st = []
bracket = {")": "("}
for i in range(k):
    n = input().strip()
    flag = True
    for i in n:
        if i == "(":
            st.append(i)
        else:
            if not st:
                flag = False
                break
            else:
                st.pop()
    if flag and not st:
        print("YES")
    else:
        print("NO")
    st.clear()
