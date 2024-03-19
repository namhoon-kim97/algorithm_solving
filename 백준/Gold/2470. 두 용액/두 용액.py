import sys

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
a.sort()

mid = n // 2

left = 0
right = n - 1
ans = sys.maxsize
res = [0, 0]
while (
    left >= 0 and right < n and left < right
):  # ans 보다 작으면 값 업데이트, 후 처리 어케하지?
    if abs(a[left] + a[right]) < ans:
        res[0], res[1] = a[left], a[right]
        ans = abs(a[left] + a[right])

    if (
        a[left] + a[right] >= 0
    ):  # 더한 값이 양수면 right(산성)을 더 낮은 값으로 보내야함. 즉, 0으로 보내는거
        right -= 1
    else:  # 음수면 left(알칼리)를 더 큰 값으로 즉, 0으로 보내는거
        left += 1

print(*res)
