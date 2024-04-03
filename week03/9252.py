import sys

input = sys.stdin.readline
first = input().strip()
second = input().strip()
d = [[0] * (len(first) + 1) for _ in range(len(second) + 1)]  # first가 열, second가 행
for i in range(1, len(second) + 1):
    for j in range(1, len(first) + 1):
        if first[j - 1] == second[i - 1]:
            d[i][j] = d[i - 1][j - 1] + 1
        else:
            d[i][j] = max(d[i - 1][j], d[i][j - 1])

print(d[len(second)][len(first)])

ans = []
i = len(second)
j = len(first)

while i > 0 and j > 0:
    if first[j - 1] == second[i - 1]:
        ans.append(second[i - 1])
        if len(ans) == d[len(second)][len(first)]:
            break
        i -= 1
        j -= 1
    else:
        d[i][j] = max(d[i - 1][j], d[i][j - 1])
        if d[i - 1][j] > d[i][j - 1]:
            i -= 1
        else:
            j -= 1
print("".join(ans[::-1]))
