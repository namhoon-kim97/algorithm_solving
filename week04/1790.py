import sys

input = sys.stdin.readline

n, k = map(int, input().split())

digit = 1
cnt = 9
while k > digit * cnt:
    k -= digit * cnt
    digit += 1
    cnt *= 10

first_num = 10 ** (digit - 1)
if k > digit * (n - first_num + 1):
    print(-1)
else:
    # digit : 자리 수
    # print(first_num)
    # print(k, digit)
    ans = first_num + (k - 1) // digit
    idx = (k - 1) % digit
    print(str(ans)[idx])
