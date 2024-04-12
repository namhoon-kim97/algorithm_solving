import sys

input = sys.stdin.readline
x = int(input())
a = [64]
while x < sum(a):
    y = min(a)
    a.remove(y)
    num = y // 2
    if sum(a) + num >= x:
        a.append(num)
    else:
        a.append(num)
        a.append(num)

print(len(a))
