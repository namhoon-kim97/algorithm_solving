import sys

a = int(input())
b = int(input())
c = int(input())

x = a * b * c
a = [0 for i in range(10)]
for i in range(10):
    for num in str(x):
        if chr(i + 48) == num:
            a[i] += 1

for ans in a:
    print(ans)
