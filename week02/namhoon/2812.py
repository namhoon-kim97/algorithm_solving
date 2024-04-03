import sys

input = sys.stdin.readline
n, k = map(int, input().split())
num = int(input())

cnt = 0
str_num = str(num)
st = []

for i in range(len(str_num)):
    while st and int(str_num[i]) > st[-1] and cnt < k:
        st.pop()
        cnt += 1
    st.append(int(str_num[i]))

st = st[: len(st) - (k - cnt)]
print(*st, sep="")
