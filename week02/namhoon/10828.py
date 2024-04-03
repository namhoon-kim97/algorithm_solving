import sys

input = sys.stdin.readline

st = []
n = int(input())
while n:
    a = input().split()
    if a[0] == "push":
        st.append(a[1])
    elif a[0] == "top":
        if st:
            print(st[-1])
        else:
            print(-1)
    elif a[0] == "pop":
        if st:
            temp = st.pop()
            print(temp)
        else:
            print(-1)
    elif a[0] == "empty":
        if st:
            print(0)
        else:
            print(1)
    elif a[0] == "size":
        print(len(st))
    n -= 1
