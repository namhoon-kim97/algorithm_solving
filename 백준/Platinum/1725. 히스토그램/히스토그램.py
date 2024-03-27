import sys

input = sys.stdin.readline

n = int(input())
a = [int(input()) for _ in range(n)]
a = [n] + a
st = []
area = 0
for i in range(1, len(a)):
    while st and a[i] < a[st[-1]]:
        h = a[st.pop()]
        w = i - 1 if not st else i - st[-1] - 1
        area = max(area, h * w)
    st.append(i)

while st:
    h = a[st.pop()]
    w = n if not st else n - st[-1]
    area = max(area, h * w)
print(area)
