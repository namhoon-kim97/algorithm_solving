import sys

x = sys.stdin.readline().rstrip()
y = sys.stdin.readline().rstrip()

a = int(x)
b = int(y)
y = y[::-1]
for i in y:
    print(int(i) * a)
print(a * b)
