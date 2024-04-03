import sys

input = sys.stdin.readline
k = int(input())

st = []
for i in range(k):
    n = int(input())
    st.append(n)

standard = st.pop()
cnt = 1
while st:
    num = st.pop()
    if num > standard:
        standard = num
        cnt += 1

print(cnt)
