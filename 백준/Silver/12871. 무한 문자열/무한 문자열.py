import sys

input = sys.stdin.readline
s = input().rstrip()
t = input().rstrip()

sidx = 0
tidx = 0

while sidx < len(s) and tidx < len(t):
    if s[sidx] == t[tidx]:
        sidx += 1
        tidx += 1
        if sidx == len(s) and tidx == len(t):
            break
        elif sidx == len(s) and tidx < len(t):
            sidx = 0
        elif tidx == len(t) and sidx < len(s):
            tidx = 0
    else:
        print(0)
        exit()
print(1)
