import sys

input = sys.stdin.readline
k = int(input())

st = []
for i in range(k):
    n = int(input())
    if n == 0:
        st.pop()
    else:
        st.append(n)
print(sum(st))
