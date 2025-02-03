import sys


def solution(s):
    st = []
    for i in range(len(s)):
        if s[i] == "(":
            st.append(s[i])
        else:
            if len(st) == 0:
                return False
            else:
                st.pop()
    if len(st) != 0:
        return False
    return True


t = int(input())
for _ in range(t):
    s = input()
    if solution(s):
        print("YES")
    else:
        print("NO")
