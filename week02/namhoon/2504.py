import sys

input = sys.stdin.readline


k = input().strip()
st = []
ans = 0
temp = 1

for i in range(len(k)):
    if k[i] == "(":
        st.append(k[i])
        temp *= 2

    elif k[i] == "[":
        st.append(k[i])
        temp *= 3

    elif k[i] == ")":
        if not st or st[-1] == "[":
            ans = 0
            break
        if k[i - 1] == "(":
            ans += temp
        st.pop()
        temp //= 2

    else:
        if not st or st[-1] == "(":
            ans = 0
            break
        if k[i - 1] == "[":
            ans += temp
        st.pop()
        temp //= 3

if st:
    ans = 0

print(ans)
