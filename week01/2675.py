t = int(input())
for _ in range(t):
    r, s = input().split()
    print("".join([x * int(r) for x in s]))
