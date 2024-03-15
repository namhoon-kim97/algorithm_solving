a = int(input())

for i in range(1, a + 1):
    x = ""
    for j in range(i):
        x += "*"
    print(x)
