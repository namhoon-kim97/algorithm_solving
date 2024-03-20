import sys

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = sys.maxsize
res = [0, 0, 0]

for i in range(n - 2):
    left = i + 1
    right = n - 1
    while left < right:
        total = a[i] + a[left] + a[right]
        if abs(total) < ans:
            ans = abs(total)
            res = [a[i], a[left], a[right]]
        if total < 0:
            left += 1
        elif total > 0:
            right -= 1
        else:
            break
res.sort()
print(*res)
